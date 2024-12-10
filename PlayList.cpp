// Write your name and date here
// Playlist method implementations for CMPT 225 assignment 1 (Part 1)
// Author: Peter Phuc
// Date: September 2024
// Sources: google, Professor John Edgar demo code

#include "PlayList.h"

// PlayList method implementations go here
// Constructor (Initializes an empty PlayList)
PlayList::PlayList() {

    // Initializing the private members
    head = nullptr;
    song_list = 0;
}

// Copy constructor: creates a copy of the playList
PlayList::PlayList(const PlayList& pl) {

    PlayListNode* next = nullptr;
    PlayListNode* current = pl.head;
    while (current != nullptr) {
        insert(current->song, song_list); // Insert at the end
        current = current->next;
    }
}

// Destructor: deallocates all nodes in the list to avoid memory leaks
PlayList::~PlayList() {

    PlayListNode* current = head;
    while (current != nullptr) {
        PlayListNode* next = current->next;
        delete current;
        current = next;
    }
}

// Assignment operator: Deep copies the provided PlayList into this one
PlayList& PlayList::operator=(const PlayList& pl) {

    if (this == &pl) { // Check for self-assignment
        return *this;
    }

    // clear the existing playlist
    while (head != nullptr) {
        PlayListNode* temp = head;
        head = head->next;
        delete temp;
    }

    head = nullptr;
    song_list = 0;

    // deep copy of the playlist
    PlayListNode* current = pl.head;
    unsigned int pos = 0;
    while (current != nullptr) {
        insert(current->song, pos);
        current = current->next;
        ++pos;
    }

    return *this;
}

// inserting nodes
void PlayList::insert(Song sng, unsigned int pos) {

    PlayListNode* new_Node = new PlayListNode(sng);

    if (pos == 0) {  // Insert at the head       
        new_Node->next = head;
        head = new_Node;
    } 
    else {
        PlayListNode* current = head;
        for (unsigned int i = 0; i < pos - 1; ++i) {
            current = current->next;
        }
        new_Node->next = current->next;
        current->next = new_Node;
    }

    ++song_list;
}

// deleting/removing the nodes
Song PlayList::remove(unsigned int pos) {

    PlayListNode* delete_Node; // pointer to the node to be deleted
   
    if(pos == 0) {
        delete_Node = head;
        head = head->next; // make the second node the head
    }
    else {
        PlayListNode* prev_Node = head;
        int i = 0;

        // loop to find the previous node for the node to be deleted
        while((unsigned)i < pos - 1){
            prev_Node = prev_Node->next;
            i++;
        }
        delete_Node = prev_Node->next; // node to be deleted
        prev_Node->next = delete_Node->next; // linking back the list together        
    }
    
    Song deleted_Song = delete_Node->song;
    song_list--;

    delete delete_Node; // Node deleted
    return deleted_Song;
}

// swapping node positiion
void PlayList::swap(unsigned int pos1, unsigned int pos2) {

    // initialize pointers
    PlayListNode* prev_NodeA = nullptr;
    PlayListNode* prev_NodeB = nullptr;
    PlayListNode* current_NodeA = head; // pointer to the head
    PlayListNode* current_NodeB = head; 

    // for loop to find the node at pos1
    for (unsigned int i = 0; i < pos1; ++i) {
        prev_NodeA = current_NodeA;
        current_NodeA = current_NodeA->next;
    }

    // for loop to find the node at pos2
    for (unsigned int j = 0; j < pos2; ++j) {
        prev_NodeB = current_NodeB;
        current_NodeB = current_NodeB->next;
    }

    // if the previous node is NULL, swap the head node
    if (prev_NodeA == nullptr) {
        head = current_NodeB; // swapped with head
    } 
    else {
        prev_NodeA->next = current_NodeB; // swapped normally by changing the next pointer of the previous node
    }

    // if previous node is NULL, swap the head node
    if (prev_NodeB == nullptr) {
        head = current_NodeA; // swapped with head
    } 
    else {
        prev_NodeB->next = current_NodeA; // swapped normally by changing the next pointer of the previous node
    }

    // swapped node next pointers
    PlayListNode* temp = current_NodeA->next;
    current_NodeA->next = current_NodeB->next;
    current_NodeB->next = temp;
}


// get info of the playlist
Song PlayList::get(unsigned int pos) const {

    PlayListNode* current = head;
    for (unsigned int i = 0; i < pos; ++i) {
        current = current->next;
    }

    return current->song;
}

// returns number of songs in the playlist
unsigned int PlayList::size() const {

    return song_list;
}