# CMPT225 Heaps
You are to implement and test a Heap template class, and an associated function. 

Please read the requirements carefully, paying attention to the names and input and output requirements of the class and its methods. We will be testing your class in our test program, so if you do not follow the requirements the test program will not compile, and will not be marked. As usual refer to the General Requirements page.

*The Template Class Lab may be helpful, and this (unused) lab on template functions.

Part 1 - Heap Class
You must implement a Heap template class named HeapT to store data of any (comparable) type. This class must be implemented using an array - not a vector - as discussed in the heap presentation. You are to implement a min heap.

The HeapT class should implement the following public methods:

constructor(int) – creates a HeapT with an underlying array capacity equal to its integer parameter
copy constructor – a constructor that creates a deep copy of its constant Heap reference parameter
destructor – deallocates dynamic memory allocated by the HeapT
operator= – overloads the assignment operator for HeapT– (deep) copies its  constant Heap reference parameter into the calling object and returns a reference to the calling object; deallocates dynamic memory as necessary and behaves appropriately under self-assignment
insert – inserts its template parameter in the heap, while maintaining the heap properties; if the heap is full throws a runtime_error
remove – removes and returns the root, while maintaining the heap properties; if the heap is empty throws a runtime_error
peek – returns the root; if the heap is empty throws a runtime_error
merge – returns a Heap object that contains the values in the calling object and its constant reference Heap parameter; neither the calling object nor the parameter should be modified; if the calling object and parameter are both empty, the returned heap should be empty; if the calling object and parameter are the same; the returned heap should be generated as usual (and will therefore contain duplicates).
size – returns the number of items stored in the heap, as an int, must run in constant time
Additional Notes
The calling object should be made constant for any method where the calling object's attribute values should not change
You may (and should) implement helper methods
Do not use variable length arrays (VLAs) in your solution; a VLA is an array whose size is specified with a variable (int arr[n]). VLAs are not part of the C++ standard and will not compile in some environments. Instead use new to create an array  in dynamic memory and assign it to a pointer
Your class may include private attributes other than the underlying array that you deem necessary
Method parameters and return values are noted (and highlighted) in the method descriptions - you must not add additional parameters to the methods; if the method description does not mention a parameter it does not have one, similarly if no return value is mentioned the method is void (or a constructor or destructor)
Implementation Hints
The way I would suggest approaching writing the assignment is something like this:

Create a new project with a file that contains a main function that you will use for testing; add a new (empty) HeapT class to the project; then compile and run your project to make sure it is set up correctly
Write your HeapT class as a regular, non-template, class that stores a base type, like an int, testing methods as you implement them
Write, and thoroughly test, one or two methods at a time.
Once your class is working perfectly convert it into a template class
Note that Bjarne Stroustrup recommends implementing template classes by first implementing a non-template class version - and I suspect his advice is worth following!

File Structure
Template classes are often contained in a single .h file as there are compilation issues with breaking them down into separate files, and this is what I want you to do for this assignment. I still want you to keep the implementation separate from the interface as much as possible within this structure, so your method implementations should appear below your Heap class definition. Your .h file will therefore have this general structure.

#pragma once //include guard
include statements

class HeapT
{
  …
};

Heap method implementations
Simple Test
Below is a simple test function for your HeapT. If you are unable to compile and run this program it is very likely that we will not be able to compile and run your submission and will therefore not mark your assignment. This test function is not in any way intended to be a comprehensive test of your class so successfully running it does not mean that you will get full marks for the assignment (or, for that matter, any marks). However, it will demonstrate that there is a reasonable probability that we can compile and run your program, allowing us to test each of your methods in detail.

void simpleTest()
{
    // Int Heap Tests
    HeapT<int> pq1(4);

    pq1.insert(3);
    pq1.insert(1);
    pq1.insert(42);

    int peek = pq1.peek();
    cout << "pq1 root = " << peek << endl; //1
    int urgent = pq1.remove();
    cout << "pq1 root = " << pq1.peek() << endl; //3
    cout << "pq1 size = " << pq1.size() << endl; //2

    HeapT<int> pq2(pq1);
    pq2.insert(-42);
    HeapT<int> pq3 = pq1.merge(pq2); // should contain duplicates
    cout << "pq3 size = " << pq3.size() << endl; //5
    cout << "pq3 root = " << pq3.peek() << endl; //-42

    // largestm test (comment out if just testing HeapT)
    vector<int> v = { 7, 11, 3 };
    vector<int> maxm = largestm<int>(v, 1);
}
Part 2 - Largest m Values
Write a template function called largestm that has two parameters: the first is a vector containing n elements of the template type, the second is an integer referred to as m.

The function should return a vector that contains the m largest values in the function's vector parameter, in descending order.

If the size of the vector parameter is less than or equal to m, the result should contain all the values in the vector parameter (and no more). That is,  the size of the result should be minimum of m and the vector parameter size.

Requirements
Your solution must use an object of your heap template class
The elements in the vector parameter may be unordered and you must not sort them, you are also not allowed to use the STL sort (or reverse) algorithm to alter the results vector
Other than using a heap object, the function is independent of your heap, class - it is not a heap class method
Your solution should run in at most O(n log m) time, where n is the size of the vector parameter
Example
input: {10,5,2,8,6,4,3,9,1} n = 9, m = 4

output: {10,9,8,6}

File Structure
Write your function in a separate file from your HeapT.h file. This file must be named largestm.h.
