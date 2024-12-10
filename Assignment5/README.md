# CMPT225 AVL Trees
In this assignment, your task is to create a class called Wordlist that counts how many times each word appears in a file. The class must use an AVL tree as its underlying representation — vectors, arrays, or other container data structures are not allowed. The data in the tree should be sorted by word - using the standard C++ comparison operators. Note that the Wordlist class is an AVL tree — you should not be implementing the Wordlist class and a separate AVL tree class.

When it’s done, you’ll be able to write code like this:

Wordlist lst("tiny_shakespeare.txt");
lst.printStatistics();
Which prints:

Number of different words: 25670
    Total number of words: 202651
       Most frequent word: the 5437
     Number of singletons: 14919 (58%)
Files
WordList.h Download WordList.h- an incomplete .h file for your project
Wordlist.cpp Download Wordlist.cpp- an incomplete .cpp file for your project
small.txt Download small.txt- a small test file you can use for testing
smallout.txt Download smallout.txt- the result of running the Wordlist printWords method on small.txt.
tiny_shakespeare.txt Download tiny_shakespeare.txt- a larger text file you can use for testing
tiny_shakespeare_out.txt Download tiny_shakespeare_out.txt- the result of running the Wordlist printWords method on tiny_shakespeare.txt.
Public Methods
Methods must preserve the AVL balance and binary search tree properties.

default constructor – creates an empty Wordlist (whose root is a null pointer).
file constructor - a constructor that takes the name of a file as a string as input, and adds all the words in that file to the Wordlist object as described under insert.
copy constructor – a constructor that creates a deep copy of its constant Wordlist reference parameter.
operator= – overloads the assignment operator for Wordlist objects to make a deep copy of its constant Wordlist reference parameter and return a reference to the calling object. The operator should behave correctly under self assignment.
destructor – deletes dynamic memory allocated by the tree.
insert – if the Wordlist does not contain the method's string parameter, it inserts the string into the Wordlist with a count of one; if the Wordlist does contain the string it increments the string's count.
remove – removes the method's string parameter from the tree and returns true; if the tree does not contain the parameter returns false; note that if there is a matching string parameter the node should be removed regardless of the count.
getCount - returns an integer equal to the number of times its string parameter is in the word list.
contains– returns true if the string parameter is in the word list and false otherwise; hint: use getCount to implement this.
differentWords– returns an integer equal to the the number of distinct words in the word list (i.e. the number of nodes).
totalWords– returns an integer equal to the the total number of words in the word list (i.e. the sum of the word counts).
mostFrequent– returns a string consisting of the word with the largest count and its count in the format word count (e.g. the 5437); throws an invalid_argument exception if the word list is empty; if there is more than one most frequent word, return the one that comes first in sorted order.
singletons– returns an integer equal to the the number of words  with a count of 1 in the word list.
printStatistics - prints statistics about the word list as shown below; this method is given to you - don't change it!
printWords - prints the words in word list in ascending sorted order - by word - with their counts as shown below.
getRoot – this method is provided to you in the .h file and you should not change it in any way. It returns a pointer to the tree's root node. Note that this violates class design principles, and in combination with the public AVLTreeNode class it allows other programmers access to the internal workings of the tree - again, not something to do in practice. Its purpose is to allow us access to the structure of your tree so that we can make sure that it is a valid AVL tree.
Print Statistics
Prints statistics about the word list in this format:

Number of different words: 25670
    Total number of words: 202651
       Most frequent word: the 5437
     Number of singletons: 14919 (58%)
This method is given to you in the wordlist.cpp file - do not change it in any way.

Print Words
Prints the words in word list in a numbered list in ascending sorted order - by word - with their counts.

1. This 1
2. a 2
3. is 2
4. or 1
5. test 1
6. test? 1
7. this 1
Note that case matters, so "This" and "this" are counted as different words. Also, punctuation matters, so "test" and "test?" are counted as different.

Real life programs would likely strip out punctuation and ignore letter case, but in this assignment we want to count every word exactly as it appears in the file. This makes the code a littler simpler, and more consistent across students.

Additional Notes
Method parameters and return values are noted in the method descriptions – you must not add additional parameters to the methods (or change the return values). If the method description does not mention a parameter it does not have one, similarly if no return value is mentioned the method is void (or a constructor or destructor). 
Your underlying AVL Tree class should be implemented as described in class; note that the height attribute of tree nodes must be determined as described in class - where a leaf node has a height of 0.
The Wordlist class must have an AVLTreeNode pointer attribute for the root of the tree, and an unsigned integer attribute that records its size, you may add other attributes as you see fit.
Calling objects and parameters should be made constant when appropriate.
Helper methods and attributes of the tree should be made private.
If you are unable to complete a method return a default value – i.e. create a stub function.
AVLTreeNode Class
As part of the Wordlist implementation you should implement an AVLTreeNode class. The declaration of the AVLTreeNode class should be included in the Wordlist.h file, as indicated in the provided .h file. 

Nodes should contain the following attributes, which must all be made public, and must be given the names set out below.

word - a string
count - an unsigned int that represents the count of the word
left – AVLTreeNode pointer to the left child
right – AVLTreeNode pointer to the right child
parent – AVLTreeNode pointer to the parent
height – an unsigned int that represents the height of the node
And these methods:

Constructor - sets the word to its (only) parameter, count to 1, pointers to nullptr, and height to zero
You may create other constructors if you wish
