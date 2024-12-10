#include "StringList.h"
#include <iostream>
#include <ostream>

using namespace std;

int main() {
    StringList list;
    
    // Test insertBack
    list.insertBack("dog");
    list.insertBack("cat");
    list.insertBack("tree");
    list.insertBack("bruh");
    std::cout << "your code outputted: " << list.toString() << " " << endl; // Expected: dog -> cat -> tree -> bruh

    // Test undo for insertBack
    list.undo();
    std::cout << "your undo outputted: " << list.toString() << " "<< endl;  // Expected: dog -> cat -> tree

    // Test insertFront
    list.insertFront("bird");
    std::cout << "your code outputted: " << list.toString() << " "<< endl;  // Expected: bird -> dog -> cat -> tree

    // Test undo for insertFront
    list.undo();
    std::cout << "your undo outputted: " << list.toString() << " "<< endl;  // Expected: dog -> cat -> tree

    // Test insertBefore
    list.insertBefore(2, "hat");
    std::cout << "your code outputted: " << list.toString() << " "<< endl;  // Expected: dog -> cat -> hat -> tree

    // Test undo for insertBefore
    list.undo();
    std::cout << "your undo outputted: " << list.toString() << " "<< endl;  // Expected: dog -> cat -> tree

    // Test set operation
    list.set(2, "cow");
    std::cout << "your code outputted: " << list.toString() << " "<< endl;  // Expected: dog -> cat -> cow

    // Test undo for set
    list.undo();
    std::cout << "your undo outputted: " << list.toString() << " "<< endl;  // Expected: dog -> cat -> tree

    // Test remove
    list.remove(1);
    std::cout << "your code outputted: " << list.toString() << " "<< endl;  // Expected: dog -> tree

    // Test undo for remove
    list.undo();
    std::cout << "your undo outputted: " << list.toString() << " "<< endl;  // Expected: dog -> cat -> tree

    // Test assignment operator
    StringList anotherList;
    anotherList.insertBack("yellow");
    anotherList.insertBack("green");
    anotherList.insertBack("red");
    anotherList.insertBack("orange");
    std::cout << "your code outputted: " << anotherList.toString() << " "<< endl;  // Expected: yellow -> green -> red -> orange

    anotherList = list;
    std::cout << "your code outputted: " << anotherList.toString() << " "<< endl;  // Expected: dog -> cat -> tree

    // Test undo for assignment operator
    anotherList.undo();
    std::cout << "your undo outputted: " << anotherList.toString() << " "<< endl;  // Expected: yellow -> green -> red -> orange

    // Test removeAll
    list.removeAll();
    std::cout << "your code outputted: " << list.toString() << " "<< endl;  // Expected: (empty list)

    // Test undo for removeAll
    list.undo();
    std::cout << "your undo outputted: " << list.toString() << " "<< endl;  // Expected: apple -> banana

    return 0;
}
