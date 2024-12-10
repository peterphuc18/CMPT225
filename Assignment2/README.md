# CMPT225
You are to implement and test an undo feature for the StringList class - which is given to you.

Please read the requirements carefully, paying attention to the names and input and output requirements of the class and its methods. 
We will be testing your class in our test program, so if you do not follow the requirements the test program will not compile, and will not be marked. As usual refer to the General Requirements page.

StringList Class
The StringList class is somewhat similar to the PlayList class from assignment 1 except that it stores strings not songs, and your job is to implement its undo method, making it an undoable list.

Implementation

Your implementation must follow these rules.

Do not delete any of the StringList method, or change the prototype of any of the methods. You may change the implementation of existing methods where necessary, but they must still behave in the same way. Your completed StringList with undo implemented must still pass all of the tests in StringListTest.cpp.
You must not change the public methods in StringList.h. However, you may add helper functions and classes (or structs) to StringList.h as needed.
You must implement undo() using a private stack class that is accessible only inside the StringList class and that is defined in StringList.h.
The undo stack should not be copied by the copy constructor (i.e. don't change the copy constructor).
You must implement the stack yourself with a dynamic array (not a vector), as described in class. 
The stack's underlying array should initially be of capacity 4. The underlying array should double in size when inserted to when it is full.
You must not add any #include or #pragma statements to StringList.h or StringList.cpp.
StringList Public Methods
The class has the following public methods. I've noted which have to be undone, this is also shown in the StringList .h and .cpp files.

StringList()
StringList(const StringList&)
StringList& operator=(const StringList& other) - undoable
~StringList()
int size() const
bool empty() const
string get(int i) const
int index(string str) const
bool contains(string str) const
bool operator==(const StringList& sl) const
bool operator!=(const StringList& sl) const
string toString() const
void set(int i, string str) - undoable
void insertBefore(int pos, string str) - undoable
void insertFront(string str) - undoable
void insertBack(string str) - undoable
void remove(int pos) - undoable
void removeAll() - undoable
void undo()
void print() const;
Getting Started
Before making any changes to StringList download all of the assignment files and compile and run StringListTest.cpp to make sure that it runs without any errors.

Designing Undo
As mentioned, you must implement undo() using at least one private stack implemented with an array inside the StringList class. You can modify Stringlist only as described above.
One idea for how undo can work is that every time Stringlist is modified by one of its undoable methods, it pushes the inverse operation on the top of an undo stack. When undo() is called, it pops the top of the stack and applies that operation to the list, thus undoing the most recent operation.
All the methods in Stringlist marked as “undoable” should work with undo(). Note that undo() cannot be undone: you are not implementing redo in this assignment.
Here are some examples of how specific methods should work.

Undoing Insert Before
Suppose lst is {"dog", "cat", "tree"}, and you call lst.insertBefore(3, "hat"), making it {"dog", "cat", "tree", "hat"}. It should push the operation remove string at index 3 on the undo stack. You could store it as a short string command, e.g. REMOVE 3. If you now call lst.undo(), the REMOVE 3 command on top of the stack is popped and applied to the list, e.g. the string at index 3 is removed, leaving the list in the state it was in before calling insertBefore, i.e. {"dog", "cat", "tree"}.

In code:

// lst == {"dog", "cat", "tree"}

lst.insertBefore(3, "hat");
// lst == {"dog", "cat", "tree", "hat"}

lst.undo();
// lst == {"dog", "cat", "tree"}

lst.insertBefore(1, "shoe");
// lst == {"dog", "shoe", "cat", "tree"}

lst.undo();
// lst == {"dog", "cat", "tree"}
Undoing Set
For set, suppose that lst is {"yellow", "green", "red", "orange"}, and so lst.get(2) returns "red". If you call lst.set(2, "cow"), then you should push the operation set location 2 to "red" onto the undo stack, and then over-write location 2 with "cow". You could format the operation like "SET 2 red". Calling lst.undo() pops the top command of the stack and applies it to the list, e.g. the string at index 2 is set to "red" and the list is in the state it was in before calling set, i.e. {"yellow", "green", "red", "orange"}.

In code:

// lst == {"yellow", "green", "red", "orange"}

lst.set(2, "cow");
// lst == {"yellow", "green", "cow", "orange"}

lst.undo();
// lst == {"yellow", "green", "red", "orange"}
Undoing Remove
For remove, suppose lst is {"dog", "cat", "tree"}. If you call lst.remove(1), you should then push the operation insert "cat" at index 1 onto the stack, and then remove the string at index 1 so it becomes {"dog", "tree"}. You could format the operation as "INSERT 1 cat". If you now call lst.undo(), the command on top of the stack is popped and applied to the list, e.g. the string "cat" is inserted at index 1, and the list is in the state it was in before calling remove, i.e. {"dog", "cat", "tree"}.

In code:

// lst == {"dog", "cat", "tree"}

lst.remove(1);
// lst == {"dog", "tree"}

lst.undo();
// lst == {"dog", "cat", "tree"}
Undoing Assignment Operator
For operator=, suppose lst1 is {"dog", "cat", "tree"}, and lst2 is {"yellow", "green", "red", "orange"}. If you call lst1 = lst2;, then you should push the command set lst1 to {"dog", "cat", "tree"} onto the stack, and then assign lst1 to lst2. You could format the command as "SET lst dog cat tree". Calling lst1.undo() pops the command on top of the stack and applies it to the list, e.g. lst1 is set to the state it was in before calling operator=, i.e. {"dog", "cat", "tree"}.

In code:

// lst1 == {"dog", "cat", "tree"}
// lst2 == {"yellow", "green", "red", "orange"}

lst1 = lst2;
// lst1 == {"yellow", "green", "red", "orange"}
// lst2 == {"yellow", "green", "red", "orange"}

lst1.undo();
// lst1 == {"dog", "cat", "tree"}
// lst2 == {"yellow", "green", "red", "orange"}
As this shows, when you undo operator=, the entire list of strings is restored in one call to undo().

Undoing Other Methods
undo() should undo all the other methods in Stringlist that are marked as “undoable” in the source code comments. As mentioned above, undo() is not undoable. There is no “re-do” feature in this assignment.

Main Function
You should write a main function in a separate file (or StringListTest.cpp) use your main function (and other test functions) to test your implementation of undo. You should not submit the file containing the main function.

I would strongly suggest compiling and running your program after you refactor each method (or couple of methods), do not try to complete the entire assignment before testing it as this will almost certainly end up being considerably more work.
