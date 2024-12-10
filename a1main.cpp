// Write your name and date here
// Main Program for CMPT 225 assignment 1 (Part 2 & 3)
// Author: Peter Phuc
// Date: September 2024
// Sources: google

/* 
Part 3
O Notation
PlayList Methods:

1) Default constructor: O(1) --> The default constructor initializes the private variables. This operation doesn't depend on the size of the list therefore, complexity is constant
2) Destructor: O(n) --> The destructor traverse the entrire list and deletes each node. As the number of nodes increase the time grows linearly, making it O(n) where n is the size of the list 
3) Copy constructor: O(n) --> The copy constructor copies and creates a new list by iteration through the nodes of the passed list. Here, it traverses the entire list making the time complexity O(n) where n is the size of the list
4) Overloaded assignment operator: O(n) --> The assignment operator is similar to the copy constructor, as it first deletes existing list then copies each element from the passed list. 
5) Insert: O(n) --> Inserting a song requires traversing the list to find the specified position. Here, the worst-case running time would be inserting a node in the last position. In this scenario we traverse the list until (n-1)th node, so this operation would depend on the size(n) of the list 
6) Remove: O(n) --> Removing a song requires traversing the list to find the specified node/position. Here, the worst-case running time would be deleting the last node in the list. In this scenario we traverse the list until (n-1)th node to find the second last node, so this operation depends on the size(n) of the list 
7) Get: O(n) --> The get method involves traversing the list to to find the node at the given position. Here, the worst-case running time would be finding the last node as it needs to go through all the n nodes
8) Swap: O(n) --> The swapping method requries locating the nodes/positions for two songs. Here, the worst-case running time would be swapping the last node and the second last node as we need to traverse the entire list for that
9) Size: O(1) --> In the size function we are returning the private variable song_list, done in constant time

Main Function Commands:

1) Enter a song: --> Given a valid input, the complexity of this command is O(n) because it calls the insert method, which has the worst case complexity of O(n)
2) Remove a song: --> Given a valid input, the complexity of this command is O(n) because it calls the remove method, which has the worst case complexity of O(n)
3) Swap two songs: --> Given a valid inputs, the complexity of this command is O(n) because it calls the swap method, which has the worst case complexity of O(n)
4) Print all the songs: --> We traverse the list to access each position, and we call the get method each time. Since the get method has a worst-case complexity of O(n), the worst-case runtime is O(n*n) due to the amount of size(n) in the list

*/

#include "PlayList.h"
#include "Song.h"
#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::getline;

int main() {

    int user_input = -1;
    PlayList playlist; // creating the playlist object
    std::cout << "Menu:" << std::endl;
    std::cout << "1 - Enter a song in the play list at a given position \n2 - Remove a song from the play list at a given position \n3 - Swap two songs in the play list \n4 - Print all the songs in the play list \n5 - Quit\n\n";
    
    // while loop continues program until the user inputs 5
    while(user_input != 5) {
        
        std::cout << "Enter 1 (insert), 2 (remove), 3 (swap), 4 (print) or 5 (quit): ";    
        std::cin >> user_input;

        if(user_input < 1 || user_input > 5) {
            std::cout << "Invalid input. Please enter a number between 1 and 5.\n";
            continue;
        }
        
        // initializing input variables
        string song_name = " ";
        string artist = " ";
        
        int length = 0; // song duration
        int pos = -1; // initialize to -1 for position of stack/list b/c when things added it will start at 0

        // for inserting a node
        if(user_input == 1) {
            
            // input for info about song
            std::cout << "Song name: ";
            std::getline(cin >> std::ws, song_name);
            
            std::cout << "Artist: ";
            std::getline(cin >> std::ws, artist);
            
            std::cout << "Length: ";
            std::cin >> length;
            
            // if it's the first song, the printed information is different
            if(playlist.size() == 0) {
                
                while(pos != 1) {
                    
                    std::cout << "Position(1): ";
                    std::cin >> pos;    
                }
            }
            else {
                
                // prompting the user for a valid input
                while(pos < 0 || (unsigned)pos > playlist.size() + 1) {
                    std::cout << "Position (1 to "<< playlist.size() + 1 <<"): ";
                    std::cin >> pos;
                }
            }    
                 
            Song new_song = Song(song_name, artist, length); // creating a song object using the inputs inputted
            playlist.insert(new_song, pos - 1); // inserting the node in the playlist (pos - 1 b/c we set the pos initially at whatever pos we set)
            std::cout << "You entered "<< song_name << " at position "<< pos <<" in the playlist\n" << std::endl;
        }
        // if the user wants to remove a node
        else if(user_input == 2) {

            // for when the playlist is empty
            if(playlist.size() == 0) {
                std::cout << "Nothing to remove, Playlist is empty\n" << std::endl;
            }

            // if the playlist is not empty
            else {
                // when there's just a single song in the playlist
                if(playlist.size() == 1) {

                    while(pos != 1) {

                        std::cout << "Position(1): ";
                        std::cin >> pos;    
                    }
                }
                else {
                    pos = 0;

                    // prompte the user for a valid input
                    while(pos <= 0 || (unsigned)pos > playlist.size()) {

                        std::cout << "Position (1 to "<< playlist.size() <<"): ";
                        std::cin >> pos;
                        
                    }
                }

                Song deleted_song = playlist.remove(pos - 1); // receiving the song object of the deleted node
                std::cout << "You removed "<< deleted_song.getName() << " from the playlist\n" << std::endl;
            }
        }

        // if the user wants to swap
        else if(user_input == 3) {
            
            // no swap when there's less than 2 songs in the playlist
            if(playlist.size() < 2) {
                std::cout << "Not enough songs to swap\n" << std::endl;
            }
            
            // otherwise, we can swap
            else {
                int pos2 = -1;
                
                // prompt the user for a valid input
                while(pos <= 0 || (unsigned)pos > playlist.size()) {
                    std::cout << "Swap song at position (1 to " << playlist.size() <<"): ";
                    std::cin >> pos;
                }  

                // prompt the user for a valid input
                while(pos2 <= 0 || (unsigned)pos2 > playlist.size()) {
                    std::cout << "with the song at position (1 to " << playlist.size() <<"): ";
                    std::cin >> pos2;
                }

                // we cannot swap same node in same position
                if(pos == pos2) { 
                    std::cout << "You cannot swap a song in the same position!\n" << std::endl;
                    continue;
                }

                playlist.swap(pos - 1, pos2 - 1); // swapping nodes
                std::cout << "You swapped the songs at positions " << pos <<" and "<< pos2 << std::endl << std::endl;
            }
        }

        // print the playlist
        else if(user_input == 4) {
    
            // print when the playlist is empty
            if(playlist.size() == 0) {
                std::cout << "Playlist is Empty\n" << std::endl;
            }
            
            // otherwise, loop through the list to print the songs
            else {

                for(unsigned int i = 1; (unsigned)i <= playlist.size(); i++) {
                    Song get_song = playlist.get(i - 1); // gets the song object
                    std::cout << i <<" "<< get_song.getName() << " ("<< get_song.getArtist() <<") " << get_song.getLength() <<"s" << std::endl;
                }
                std::cout <<"There are " << playlist.size() <<" songs in the playlist.\n" << std::endl;
            }    
        }
    }

    // print exit
    std::cout << "You have chosen to quit the program." << std::endl;
}