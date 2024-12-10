// cmpt225a2undo:
// Author: Peter Phuc
// Date: October 2024

#include "StringList.h"
#include <stdexcept>
#include <iostream>
using std::out_of_range;
using std::cout;
using std::endl;
using std::find;

// Default constructor - makes an empty list of capacity 10
StringList::StringList()
{
	capacity = 10;
	n = 0;
	arr = new string[capacity];
}

// Copy constructor
StringList::StringList(const StringList& other)
{
	copyList(other);
}

// ***UNDOABLE
// Overloaded assignment operator
StringList& StringList::operator=(const StringList& other)
{
	if(&other != this)
	{
		// if list is not empty, save the current state for undo
		if (n > 0) 
		{
			UndoCommand execute;
			execute.command = "RESTORE"; // action to restore list
			execute.i = n; // use index value to store number of elements
			execute.value = toString(); // save current string
			undoStack.push(execute); // push into stack
		}
		delete[] arr;
		copyList(other);
	}
	return *this;
}

// Destructor
StringList::~StringList()
{
	delete[] arr;
}

// ACCESSORS
// Returns the number of elements in the list
int StringList::size() const
{
	return n;
}

// Returns true if the list is empty, false otherwise
bool StringList::empty() const
{
	return n == 0;
}

// Returns the string at the given index
string StringList::get(int i) const
{
	checkBounds(i, "get");
	return arr[i];
}

// Returns the index of the first occurrence of the given string
int StringList::index(string s) const
{
	int i = 0;
	while (i < n && s != arr[i]) {
		i++;
	}
	if (i == n) {
		return -1;
	}
	else {
		return i;
	}
}

// Returns true iff the given string is in the list
bool StringList::contains(string str) const
{
	return !(index(str) == -1);
}

// Returns true if the two lists are equal, false otherwise.
// Does *not* consider any undo information when comparing two Stringlists. All
// that matters is that they have the same strings in the same order.
bool StringList::operator==(const StringList& sl) const
{
	if (size() != sl.size())
	{
		return false;
	}
	for (int i = 0; i < size(); i++)
	{
		if (get(i) != sl.get(i))
		{
			return false;
		}
	}
	return true;
}

// Returns true if the two lists are not equal, false otherwise
bool StringList::operator!=(const StringList& sl) const
{
	return !(*this == sl);
}

// Returns a string representation of the list.
string StringList::toString() const
{
	string result = "{";
	for (int i = 0; i < size(); i++)
	{
		if (i > 0) {
			result += ", ";
		}
		result += "\"" + get(i) + "\"";
	}
	return result + "}";
}


// MUTATORS

// ***UNDOABLE
// Sets the value at the given index
void StringList::set(int i, string str)
{
	checkBounds(i, "set");

	// create undo command to restore the previous value
	UndoCommand execute;
	execute.command = "SET";
	execute.i = i; // store index of the element being modified
	execute.value = arr[i]; // save current value for undoing
	undoStack.push(execute);

	arr[i] = str;
}

// ***UNDOABLE
// Inserts the given string *before* the given index
void StringList::insertBefore(int pos, string str)
{
	// Doesn't use checkBounds because it's okay to insert at the end
	if (pos < 0 || pos > size()) {
		throw out_of_range("StringList::insertBefore index out of bounds");
	}

	checkCapacity();

	// create undo command to remove the new element in case of undo
	UndoCommand execute;
	execute.command = "REMOVE";
	execute.i = pos;
	undoStack.push(execute);

	for (int i = n; i > pos; i--) {
		arr[i] = arr[i-1];
	}
	arr[pos] = str;
	n++; // increase list of size
}

// ***UNDOABLE
// Inserts the given string at the front of the list
void StringList::insertFront(string str)
{
	// no undo stack here 
	checkCapacity();
	insertBefore(0, str);
}

// ***UNDOABLE
// Inserts the given string at the back of the list
void StringList::insertBack(string str)
{
	checkCapacity();
	insertBefore(n, str);
}

// ***UNDOABLE
// Removes the element at the given index and moves elements after it down
void StringList::remove(int pos)
{
	checkBounds(pos, "remove");

	// create undo command to allow re-insertion of the removed element
	UndoCommand execute;
	execute.command = "INSERT";
	execute.i = pos;
	execute.value = arr[pos];
	undoStack.push(execute);

	// shift elements to fill the gap created by the removal
	for (int i = pos; i < n; i++) {
		arr[i] = arr[i + 1];
	}
	n--;
}

// ***UNDOABLE
// Empties the list
void StringList::removeAll()
{
	// create undo command to restore the previous state of the list
	UndoCommand execute;
	execute.command = "RESTORE";
	execute.value = toString();
	undoStack.push(execute);

	for (int i = 0; i < n; i++) {
		arr[i] = "";
	}
	n = 0;
}

// Undoes the last operation that modified the list
void StringList::undo()
{
	if (undoStack.isEmpty()) 
	{
        cout << "Nothing to undo!" << endl;
        return;
    }

	UndoCommand previous = undoStack.pop(); // get the last command from the stack
	string command = previous.command; // retrieve the command type

	if (command == "INSERT") 
	{
		insertBefore(previous.i, previous.value);
	}
	else if (command == "REMOVE") 
	{
		remove(previous.i);
	}
	else if (command == "SET") 
	{
		set(previous.i, previous.value);
	}
	else if (command == "RESTORE") 
	{
		// clear list
		removeAll();  

		string restoreList = previous.value;

		// parse the string to reinsert elements into the list
		for (int i = 1; i < restoreList.length() - 1;) {
			unsigned int start = restoreList.find('\"', i);
			unsigned int end = restoreList.find('\"', start + 1);

			// do need?
			if (start == string::npos) 
			{
				std::cerr << "Error: Start quote not found " << start << std::endl;
				break;
			}
			if (end == string::npos) 
			{
				std::cerr << "Error: End quote not found at position " << end << std::endl;
				break;
			}

			// extract the string element and insert it back into the list
			string element = restoreList.substr(start + 1, end - start - 1);
			insertBack(element); // insert the element at the end
			i = end + 1; // move to the next element
		}
	}
}

// Prints the list
void StringList::print() const
{
	for (int i = 0; i < n; i++) {
		cout << arr[i] << endl;
	}
}

// Helper function for checking index bounds.
void StringList::checkBounds(int i, string s) const
{
	if (i < 0 || i >= size()) {
		throw out_of_range("StringList::" + s + " index out of bounds");
	}
}

// POST: Doubles the capacity of the list if n == capacity
void StringList::checkCapacity()
{
	if (n == capacity) {
		capacity *= 2;
		string* temp = new string[capacity];
		
		for (int i = 0; i < n; i++) {
			temp[i] = arr[i];
		}
		delete[] arr;
		arr = temp;
	}
}

// Helper function to copy the contents of another list
void StringList::copyList(const StringList& lst)
{
	capacity = lst.capacity;
	n = lst.n;
	arr = new string[capacity];

	for (int i = 0; i < n; i++) {
		arr[i] = lst.arr[i];
	}
}