# CMPT225

You are to implement a class that stores a play list - a list of songs - and, in part 2, write a program that uses your class. The class should use a singly linked list as its underlying representation.

The PlayList class is an implementation of the list abstract data type. A list is a data type that preserves the order of its contents (they are not sorted, it is just that the order of its contents is maintained). For example, if you enter the strings milk, butter, eggs into a list in that order then the list will contain milk at its first position, butter in its second and eggs in its third. Lists allow elements to be inserted at any position and removed from any position. 

Please read the requirements carefully, paying particular attention to the names and input and output requirements of the class and its methods. We will be testing your class in our test program, if you do not follow the requirements our test program will not compile and your assignment may not be marked.


Getting Started
For this assignment we are providing you with four files to show you the intended structure of the program. These files are:

Song.h Download Song.h, the header file for the Song class - this file is complete and should not be submitted
Song.cpp Download Song.cpp, the implementation file for the Song class - this file is complete and should not be submitted
PlayList.h Download PlayList.h, the header file for the PlayList class  - this file is mostly complete, except for the private section of the class, it includes the complete definition of the PlayListNode class; the file should be submitted, 
PlayList.cpp Download PlayList.cpp, the implementation file for the PlayList class - this file is essentially empty; the file should be submitted
Songs
You are given the Song class which is contained in the Song.h and Song.cpp files. You should not edit these files in any way. A Song is a class that stores information about songs (not surprisingly). A song has the following attributes:

name - the name of the song (e.g. Bat Out of Hell, Red, Here's To Us)
artist - the name of the recording artist (e.g. Meatloaf, Taylor Swift, Halestorm)
length - the running time of the song in seconds (e.g. 592, 223, 177)
Look at the song files for further information. Note that name and artist are Standard Template Library (STL) string objects, they are not C strings.

Nodes
Your are to implement the PlayList class as a linked list. Linked lists are made up of nodes and the PlayListNode class is given to you (in the PlayList.h file). A node has the following attributes:

song - the node's data, that represents a song
next - a pointer to the next node in the list
Part 1 - PlayList Class
You are to write a PlayList class that represents a play list of songs where the order represents the order in which the songs are to be played. 

Public Methods
The method prototypes described below are given to you in the PlayList.h file as part of the PlayList class. You may not add, remove, rename or otherwise change any of these public methods. You are responsible for completing the private section of the PlayList class.

default constructor – creates an empty PlayList.
copy constructor – creates a deep copy of its constant PlayList reference parameter.
destructor – deallocates dynamic memory associated with the underlying linked list.
overloaded assignment operator – deep copies its constant PlayList reference parameter to the calling object; deallocates dynamic memory associated with the calling object's linked list; returns a reference to the calling object; should behave correctly during self-assignment.
insert – inserts its song parameter (the first parameter) at the position specified by its unsigned integer parameter (the second parameter). The first element of the list has position 0, the second position 1 and the ith position i-1. If a song is inserted at some position i then it should be inserted immediately before the song that was previously at position i (and that will be at position i+1 after the insertion). 
Example: if a play list consisted of: {Red, Bat Out of Hell, Fire and Ice, Unstoppable} and Don't Fear the Reaper was inserted at position 2 the resulting list would be: {Red, Bat Out of Hell, Don't Fear the Reaper, Fire and Ice, Unstoppable}.
get – returns the song at the position given by its unsigned integer parameter. 
remove – removes and returns the song stored at the position given by its unsigned integer parameter. 
swap - swaps the two songs at the positions given by its two unsigned integer parameters. For full marks your swap method should swap the nodes by splicing them in and out of the list, rather than swapping their contents.
size – returns an unsigned integer equal to the number of songs in the play list.
Attributes
Your class should be implemented with a singly linked list and should have the following private member variables

A pointer to the first node in the list (the list head), this should initially be set to nullptr (when the list is empty)
An unsigned int that records the number of songs in the list
Files
You should complete and submit the PlayList.h and PlayList.cpp files.

PlayList.h -This file already contains the complete implementation of the Node class, which you should not change. You should write the PlayList class definition in this file, divided into public and private sections as described in class.
PlayList.cpp - This file is empty (except for a single include statement). You should write each of the PlayList method implementations in this file.
Part 2 - Main Program
You are to write a console application in a separate file named a1main.cpp. that allows the user to create and print a play list. The program should have 5 options:

Enter a song in the play list at a given position
Remove a song from the play list at a given position
Swap two songs in the play list, given their positions
Print all the songs in the play list
Quit
The program should be controlled by a loop such that the user should be able to repeatedly enter commands until they choose to quit. The options must be numbered 1 to 5 as indicated above.

The user should be given feedback after performing the commands - see the sample run below for what is acceptable.

Input Errors
The user should be prompted to enter a number from 1 to 5 (corresponding to the commands described above). If the user enters some other value they should be prompted to enter another command. 

Similarly, if a user enters an invalid position they should be prompted to re-enter the position. Note that your program should indicate to the user what the valid position values are (just 1 if the list is empty, otherwise 1 to n).

Printing Play Lists
Play lists should be printed one song per line in order of their positions in the list. Each song should be proceeded by a number indicating its position in the list (1, 2, 3, etc.)*. The number of songs in the play list should also be printed. See the sample run for an example of what is expected. A small number of marks is allocated to the readability of your output.

*Note that this is not a 0-based position for readability.

Sample Run
Menu:
1 - Enter a song in the play list at a given position
2 - Remove a song from the play list at a given position
3 - Swap two songs in the play list
4 - Print all the songs in the play list
5 - Quit

Enter 1 (insert), 2 (remove), 3 (swap), 4 (print) or 5 (quit): 1
Song name: Red
Artist: Taylor Swift
Length: 223
Position (1): 1
You entered Red at position 1 in the play list

Enter 1 (insert), 2 (remove), 3 (swap), 4 (print) or 5 (quit): 1
Song name: Bat Out of Hell
Artist: Meatloaf
Length: 592
Position (1 to 2): 1
You entered Bat Out of Hell at position 1 in the play list

Enter 1 (insert), 2 (remove), 3 (swap), 4 (print) or 5 (quit): 1
Song name: Unstoppable
Artist: Sia
Length: 217
Position (1 to 3): 2
You entered Unstoppable at position 2 in the play list

Enter 1 (insert), 2 (remove), 3 (swap), 4 (print) or 5 (quit): 1
Song name: Fire and Ice
Artist: Ad Infinitum
Length: 275
Position (1 to 4): 3
You entered Fire and Ice at position 3 in the play list

Enter 1 (insert), 2 (remove), 3 (swap), 4 (print) or 5 (quit): 4
 1 Bat Out of Hell (Meatloaf) 592s
 2 Unstoppable (Sia) 217s
 3 Fire and Ice (Ad Infinitum) 275s
 4 Red (Taylor Swift) 223s
There are 4 songs in the play list.

Enter 1 (insert), 2 (remove), 3 (swap), 4 (print) or 5 (quit): 2
Position (1 to 4): 2
You removed Unstoppable from the play list

Enter 1 (insert), 2 (remove), 3 (swap), 4 (print) or 5 (quit): 3
Swap song at position (1 to 3): 1
with the song at position (1 to 3): 3
You swapped the songs at positions 1 and 3

Enter 1 (insert), 2 (remove), 3 (swap), 4 (print) or 5 (quit): 4
 1 Red (Taylor Swift) 223s
 2 Fire and Ice (Ad Infinitum) 275s
 3 Bat Out of Hell (Meatloaf) 592s
There are 3 songs in the play list.

Enter 1 (insert), 2 (remove), 3 (swap), 4 (print) or 5 (quit): 5
You have chosen to quit the program.

Part 3
At the top of your a1main.cpp file write in comments the O Notation worst-case running time of the methods and main function commands listed below. For full marks you must write a brief explanation (one or two sentences) for each answer.

Main Function Commands
Enter a song
Remove a song
Swap two songs
Print all the songs
