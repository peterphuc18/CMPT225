// cmpt225 a5 AVL Trees:
// Author: Peter Phuc
// Date: November 2024

#pragma once

#include <string>
#include <iostream>
using std::string;
using std::cin;
using std::cout;
using std::endl;

// This class represents a node in an AVL tree
class AVLTreeNode {
public:
	// Should have attributes named:
	// parent - pointer to parent
	// left - pointer to left child
	// right - pointer to right child
	// word - node's string data
	// count - number of times the word appears
	// height - node's height

	string word;
	unsigned int count;
	unsigned int height;

	AVLTreeNode* parent;
	AVLTreeNode* left;
	AVLTreeNode* right;

	// Constructors ...
	AVLTreeNode(const string& w) 
	{
    	word = w;			// Set the word data for the node
    	count = 1;			// Initialize the count to 1 (first occurrence)
    	left = nullptr;		// Set left and right child to nullptr 
    	right = nullptr;	// Set right child to nullptr (no children initally)
    	parent = nullptr;	// Set parent pointer to nullptr (no parent initially)
		height = 0;			// Set height to 0
	} 
};

// Wordlist class used to manage the words in an AVL tree
class Wordlist
{
private:
	// Class attributes go here
	// Your class MUST have a root node named root (below)
	AVLTreeNode* root; // DO NOT REMOVE
	unsigned int size; // number of different words

	// Helper functions
    AVLTreeNode* balance(AVLTreeNode* node); 			// Helps maintain the balance property of the AVL tree.
    int getHeight(AVLTreeNode* node) const; 			// Returns the height 
    int getBalanceFactor(AVLTreeNode* node) const; 		// Calculates the balance factor of a node.
    AVLTreeNode* rotateLeft(AVLTreeNode* node); 		// Performs a left rotation to restore balance.
    AVLTreeNode* rotateRight(AVLTreeNode* node); 		// Performs a right rotation to restore balance.
    AVLTreeNode* findMin(AVLTreeNode* node) const; 		// Finds the node with the minimum value in the subtree.
    void destroyTree(AVLTreeNode* node); 				// Recursively deletes all nodes in the subtree.
    AVLTreeNode* copyTree(AVLTreeNode* node, AVLTreeNode* parent); 	// Creates a deep copy of the subtree.
    int totalWordsHelper(AVLTreeNode* node) const; 		// Recursively counts the total number of words.
    void mostFrequentHelper(AVLTreeNode* node, string& mostFrequentWord, unsigned int& maxCount) const; // Finds the word with the highest count recursively
    int singletonsHelper(AVLTreeNode* node) const; 		// Counts the number of words with a count of 1 recursively
    void printWordsHelper(AVLTreeNode* node, unsigned int &index) const; 	// Recursively prints all words in ascending order.

public:
	// public methods go here

	// default constructor
	Wordlist();

	// file constructor
    Wordlist(const string& filename);

	// copy constructor
    Wordlist(const Wordlist& other);

	// overload
    Wordlist& operator=(const Wordlist& other);

	// destructor
    ~Wordlist();

	// insert string
    void insert(const string& word);

	// remove string from tree for true, tree does not contain string return false
    bool remove(const string& word);

	// return number of times string is in list
    int getCount(const string& word) const;

	// returns true is string is in list or false otherwise
    bool contains(const string& word) const;

	// returns integer equal to number of diff words in list
    int differentWords() const;

	// returns total number of words in list
    int totalWords() const;

	// returns word with largest count in list (if same return the one that comes first)
    string mostFrequent() const;

	// returns integer equal to number of words with a count of 1 in list
    int singletons() const;

	// Prints useful statistics about the word list
	void printStatistics() const;

	// prints words in ascending sorted order
    void printWords() const;

	// Returns the root of the AVL tree
	AVLTreeNode* getRoot() const { return root; }; // DO NOT REMOVE
};