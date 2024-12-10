// cmpt225 a5 AVL Trees:
// Author: Peter Phuc
// Date: November 2024

#include "Wordlist.h"
#include <iomanip>
#include <fstream>
#include <stdexcept>
using std::setprecision;
using std::fixed;
using std::ifstream;
using std::invalid_argument;

// Helper functions:

// Helper function to get the maximum of two values
int maxValue(int a, int b) 
{
    return (a > b) ? a : b;
}

// Balance the AVL tree
AVLTreeNode* Wordlist::balance(AVLTreeNode* node) 
{
    if (node == nullptr) 
		return nullptr;

    // Update height
    node->height = 1 + maxValue(getHeight(node->left), getHeight(node->right));

    int balanceFactor = getBalanceFactor(node);

    // Left heavy
    if (balanceFactor > 1) 
	{
        if (getBalanceFactor(node->left) < 0) 
		{
			// Perform left rotation on the left child before right rotation
            node->left = rotateLeft(node->left);
        }
        return rotateRight(node);
    }

    // Right heavy
    if (balanceFactor < -1) 
	{
        if (getBalanceFactor(node->right) > 0) 
		{
			// Perform right rotation on the right child before left rotation
            node->right = rotateRight(node->right);
        }
        return rotateLeft(node);
    }
    return node;
}

// Get height of a node
int Wordlist::getHeight(AVLTreeNode* node) const 
{
	// Returns the height of the node or -1 if the node is null
    if (node) 
	{
    	return node->height;
	} 
	else 
	{
    	return -1;
	}
}

// Get balance factor of a node
int Wordlist::getBalanceFactor(AVLTreeNode* node) const 
{
	// Balance factor = height of left subtree - height of right subtree
    if (node == nullptr)
        return 0;
    return getHeight(node->left) - getHeight(node->right);
}

// Rotate left
AVLTreeNode* Wordlist::rotateLeft(AVLTreeNode* node) 
{
	// Perform left rotation
    AVLTreeNode* newRoot = node->right;
    node->right = newRoot->left;

    if (newRoot->left) 
		newRoot->left->parent = node;

    newRoot->left = node;
    newRoot->parent = node->parent;
    node->parent = newRoot;

	// Update heights
    node->height = 1 + maxValue(getHeight(node->left), getHeight(node->right));
    newRoot->height = 1 + maxValue(getHeight(newRoot->left), getHeight(newRoot->right));
    return newRoot;
}

// Rotate right
AVLTreeNode* Wordlist::rotateRight(AVLTreeNode* node) 
{
	// Perform right rotation
    AVLTreeNode* newRoot = node->left;
    node->left = newRoot->right;

    if (newRoot->right) 
		newRoot->right->parent = node;
		
    newRoot->right = node;
    newRoot->parent = node->parent;
    node->parent = newRoot;

	// Update heights
    node->height = 1 + maxValue(getHeight(node->left), getHeight(node->right));
    newRoot->height = 1 + maxValue(getHeight(newRoot->left), getHeight(newRoot->right));
    return newRoot;
}

// Find the minimum node in the subtree (for this assignment replace with successor)
AVLTreeNode* Wordlist::findMin(AVLTreeNode* node) const 
{
	// Traverse to the leftmost node
    while (node->left != nullptr) 
	{
        node = node->left;
    }
    return node;
}

// Destroy the AVL tree
void Wordlist::destroyTree(AVLTreeNode* node) 
{
	// Recursively delete all nodes
    if (node) 
	{
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }
}

// Helper function to copy a tree
AVLTreeNode* Wordlist::copyTree(AVLTreeNode* node, AVLTreeNode* parent) 
{
    if (node == nullptr) 
		return nullptr;

	// Create a new node with the same data
    AVLTreeNode* newNode = new AVLTreeNode(node->word);
    newNode->count = node->count;
    newNode->height = node->height;
    newNode->parent = parent;

	// Recursively copy left and right subtrees
    newNode->left = copyTree(node->left, newNode);
    newNode->right = copyTree(node->right, newNode);

    return newNode;
}

// Helper function for total words
int Wordlist::totalWordsHelper(AVLTreeNode* node) const 
{
	// Recursively calculate total word count
    if (node == nullptr) 
		return 0;
    return node->count + totalWordsHelper(node->left) + totalWordsHelper(node->right);
}

// Helper function for most frequent word
void Wordlist::mostFrequentHelper(AVLTreeNode* node, string& mostFrequentWord, unsigned int& maxCount) const 
{
    if (node == nullptr) 
		return;

	// Update most frequent word if necessary
    if (node->count > maxCount || (node->count == maxCount && node->word < mostFrequentWord)) 
	{
        mostFrequentWord = node->word;
        maxCount = node->count;
    }

	// Recurse on left and right subtrees
    mostFrequentHelper(node->left, mostFrequentWord, maxCount);
    mostFrequentHelper(node->right, mostFrequentWord, maxCount);
}

// Helper function for singletons
int Wordlist::singletonsHelper(AVLTreeNode* node) const 
{
	int count;
	
    if (node == nullptr) 
		return 0;
	if (node->count == 1)
	{
		count = 1;
	}
	else
	{
		count = 0;
	}

	// Recursively count singletons in left and right subtrees
	int result = count + singletonsHelper(node->left) + singletonsHelper(node->right);
    return result;
}

// Helper function to print words
void Wordlist::printWordsHelper(AVLTreeNode* node, unsigned &index) const 
{
    if (node == nullptr) 
		return;

    printWordsHelper(node->left, index);
    cout << index++ << ". " << node->word << " " << node->count << endl; // print index of word
    printWordsHelper(node->right, index);
}

// Wordlist method implementations

// Default constructor
Wordlist::Wordlist()
{
	root = nullptr;
	size = 0;
}

// File constructor
Wordlist::Wordlist(const string& filename) : root(nullptr), size(0) 
{
    ifstream file(filename);
    string word;

	// Read words from file and insert into the AVL tree
    while (file >> word) 
	{
        insert(word);
    }
}

// Copy constructor
Wordlist::Wordlist(const Wordlist& other) : root(nullptr), size(0) 
{
    if (other.root != nullptr) 
	{
		// Deep copy of the other tree
		root = copyTree(other.root, nullptr);
        size = other.size;
    }
}

// Assignment operator
Wordlist& Wordlist::operator=(const Wordlist& other) 
{
    if (this == &other) 
		return *this; // Handle self-assignment

	// Destroy current tree and copy the other tree
    destroyTree(root);
    root = nullptr;
    size = 0;

    if (other.root != nullptr) 
	{
        root = copyTree(other.root, nullptr);
        size = other.size;
    }
    return *this;
}

// Destructor
Wordlist::~Wordlist() 
{
	// Free memory by destroying the tree
    destroyTree(root);
}

// Insert a word into the AVL tree
void Wordlist::insert(const string& word) 
{
    if (root == nullptr) 
	{
		// If tree is empty, create the root node
        root = new AVLTreeNode(word);
        size++;
    } 
	else 
	{
        AVLTreeNode* current = root;
        AVLTreeNode* parent = nullptr;
        
		// Traverse the tree to find the insertion point
		while (current != nullptr) 
		{
            parent = current;
            if (word < current->word) 
			{
            	current = current->left;
            } 
			else if (word > current->word) 
			{
                current = current->right;
            } 
			else 
			{
				// Word already exists, increment its count
                current->count++;
                return;
            }
        }
		// Insert the new node as a child of the parent
        if (word < parent->word) 
		{
            parent->left = new AVLTreeNode(word);
            parent->left->parent = parent;
        } 
		else 
		{
            parent->right = new AVLTreeNode(word);
            parent->right->parent = parent;
        }
        size++;
    }
    root = balance(root);
}

// Remove a word from the AVL tree
bool Wordlist::remove(const string& word) 
{
    AVLTreeNode* current = root;
    AVLTreeNode* parent = nullptr;

	// Search for the node to remove
    while (current != nullptr && current->word != word) 
	{
        parent = current;
        if (word < current->word) 
		{
            current = current->left;
        } 
		else 
		{
            current = current->right;
        }
    }
    if (current == nullptr) 
	{
        return false; // Word not found
    }

    if (current->left == nullptr || current->right == nullptr) 
	{
		// Case: Node has 0 or 1 child
        AVLTreeNode* child = (current->left) ? current->left : current->right;
        if (parent == nullptr) 
		{
			// Removing root node
            root = child;
        } 
		else if (parent->left == current) 
		{
            parent->left = child;
        } 
		else 
		{
            parent->right = child;
        }
        if (child != nullptr) 
		{
            child->parent = parent;
        }
        delete current;
    } 
	else 
	{
		// Case: Node has 2 children
        AVLTreeNode* successor = findMin(current->right);
        current->word = successor->word;
        current->count = successor->count;
        remove(successor->word);
    }
    size--;
    root = balance(root);
    return true;
}

// Get the count of a word in the AVL tree
int Wordlist::getCount(const string& word) const 
{
    AVLTreeNode* current = root;

    while (current != nullptr) 
	{
        if (word == current->word) 
		{
            return current->count;
        } 
		else if (word < current->word) 
		{
            current = current->left;
        } 
		else 
		{
            current = current->right;
        }
    }
    return 0;
}

// Check if a word is in the AVL tree
bool Wordlist::contains(const string& word) const 
{
    return getCount(word) > 0;
}

// Get the number of different words in the AVL tree
int Wordlist::differentWords() const 
{
    return size;
}

// Get the total number of words in the AVL tree
int Wordlist::totalWords() const 
{
    return totalWordsHelper(root);
}

// Get the most frequent word in the AVL tree
string Wordlist::mostFrequent() const 
{
    if (root == nullptr) 
		throw invalid_argument("The word list is empty.");

    string mostFrequentWord = root->word;
    unsigned int maxCount = root->count;

    mostFrequentHelper(root, mostFrequentWord, maxCount);
    return mostFrequentWord + " " + std::to_string(maxCount);
}

// Get the number of singletons in the AVL tree
int Wordlist::singletons() const 
{
    return singletonsHelper(root);
}

// Print words in ascending sorted order
void Wordlist::printWords() const 
{
    if (root == nullptr)
    {
        std::cout << "" << std::endl;
    }
	unsigned int index = 1; // Reset the index for each print call, keep track of current index
    printWordsHelper(root, index);
}

// Prints useful statistics about the word list
void Wordlist::printStatistics() const
{
    cout << "Number of different words: " << differentWords() << endl;
    cout << "    Total number of words: " << totalWords() << endl;
    cout << "       Most frequent word: " << mostFrequent() << endl;
    cout << "     Number of singletons: " << singletons()
         << setprecision(0) << fixed
         << " (" << 100.0 * singletons() / differentWords() << "%)"
         << endl;
}

/*
// test from professor
void simpleTest()
{
    Wordlist wl1;
    Wordlist wl2("small.txt");
    Wordlist wl3(wl2);
    wl1 = wl2;

    wl1.insert("aardvark");
    bool isAardvark = wl1.contains("aardvark");
    int aardvarkCount = wl1.getCount("aardvark");
    bool removed = wl1.remove("aardvark");

    wl1.printWords();
    wl1.printStatistics();

    AVLTreeNode* root = wl1.getRoot();
}

void simpleTest2()
{
    Wordlist wl1;
    Wordlist wl2("tiny_shakespeare.txt");
    Wordlist wl3(wl2);
    wl1 = wl2;

    wl1.insert("aardvark");
    bool isAardvark = wl1.contains("aardvark");
    int aardvarkCount = wl1.getCount("aardvark");
    bool removed = wl1.remove("aardvark");

    wl1.printWords();
    wl1.printStatistics();

    AVLTreeNode* root = wl1.getRoot();
}

// for testing the 2 test case from professor
int main()
{
    simpleTest();
	simpleTest2();
    return 0;
}
*/