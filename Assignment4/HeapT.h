// cmpt225 a4 Heaps (Part1):
// Author: Peter Phuc
// Date: November 2024

#pragma once // include guard

#include <stdexcept>
#include <array>
#include <iostream>

// template class for a min heap
template <typename T>
class HeapT
{
private:
    T* heapArray; // pointer to heap array
    int capacity; // max capacity of the heap
    int currentSize; // current number of elements in the heap

    // helper functions maintaing heap property for after insertion and removal
    void heapUp(int index);
    void heapDown(int index);

// setting all public methods
public:
    HeapT(int capacity);
    HeapT(const HeapT& other);
    ~HeapT();

    HeapT& operator=(const HeapT& other);

    void insert(const T& value);
    T remove();
    T peek() const;
    HeapT merge(const HeapT& other) const;
    int size() const;

    /*
    // friend function to support std::cout for test case made
    friend std::ostream& operator<<(std::ostream& os, const HeapT& heap) {
        for (int i = 0; i < heap.currentSize; ++i) {
            os << heap.heapArray[i] << " ";
        }
        return os;
    }
    */
};

// helper function: maintains heap property by moving element at index up (bubbleUp) (like in lecture)
template <typename T>
void HeapT<T>::heapUp(int index)
{
    while (index > 0)
    {
        int parentIndex = (index - 1) / 2; // from lecture
        if (heapArray[index] < heapArray[parentIndex])
        {
            std::swap(heapArray[index], heapArray[parentIndex]);
            index = parentIndex;
        }
        else
        {
            break;
        }
    }
}

// helper function: maintains heap property by moving the element at index down (bubbleDown)
template <typename T>
void HeapT<T>::heapDown(int index)
{
    int leftChild; 
    int rightChild; 
    int minIndex;
    
    while (index < currentSize)
    {
        leftChild = 2 * index + 1;
        rightChild = 2 * index + 2;
        minIndex = index;

        if (leftChild < currentSize && heapArray[leftChild] < heapArray[minIndex])
        {
            minIndex = leftChild;
        }
        if (rightChild < currentSize && heapArray[rightChild] < heapArray[minIndex])
        {
            minIndex = rightChild;
        }

        // swap if needed then continue 
        if (minIndex != index)
        {
            std::swap(heapArray[index], heapArray[minIndex]);
            index = minIndex;
        }
        else
        {
            break;
        }
    }
}

// constructor: initalizes heap with given cap
template <typename T>
HeapT<T>::HeapT(int cap)
{
    this->capacity = cap;
    this->currentSize = 0;
    this->heapArray = new T[cap];
}

// copy constructor: creates deep copy of another heap
template <typename T>
HeapT<T>::HeapT(const HeapT& other)
    : capacity(other.capacity), currentSize(other.currentSize)
{
    heapArray = new T[capacity];
    for (int i = 0; i < currentSize; i++)
    {
        heapArray[i] = other.heapArray[i];
    }
}

// Destructor: deallocates dynamic allocated memory
template <typename T>
HeapT<T>::~HeapT()
{
    delete[] heapArray;
}

// Assignment Operator: assigns values from another heap to current 
template <typename T>
HeapT<T>& HeapT<T>::operator=(const HeapT& other)
{
    if (this != &other)
    {
        delete[] heapArray;

        capacity = other.capacity;
        currentSize = other.currentSize;
        heapArray = new T[capacity];
        for (int i = 0; i < currentSize; i++)
        {
            heapArray[i] = other.heapArray[i];
        }
    }
    return *this;
}

// Insert
template <typename T>
void HeapT<T>::insert(const T& value)
{
    if (currentSize == capacity)
    {
        throw std::runtime_error("Heap is full");
    }
    heapArray[currentSize] = value;
    heapUp(currentSize); // maintain 
    currentSize++;
}

// Remove
template <typename T>
T HeapT<T>::remove()
{
    if (currentSize == 0)
    {
        throw std::runtime_error("Heap is empty");
    }
    T root = heapArray[0];
    heapArray[0] = heapArray[currentSize - 1];
    currentSize--;
    heapDown(0); // maintain
    return root;
}

// Peek
template <typename T>
T HeapT<T>::peek() const
{
    if (currentSize == 0)
    {
        throw std::runtime_error("Heap is empty");
    }
    return heapArray[0];
}

// Merge: merges current heap with another heap and returns merged heap
template <typename T>
HeapT<T> HeapT<T>::merge(const HeapT& other) const
{
    HeapT<T> mergeHeap(this->capacity + other.capacity);

    for (int i = 0; i < this->currentSize; i++)
    {
        mergeHeap.insert(this->heapArray[i]);
    }
    for (int i = 0; i < other.currentSize; i++)
    {
        mergeHeap.insert(other.heapArray[i]);
    }
    return mergeHeap;
}

// Size
template <typename T>
int HeapT<T>::size() const
{
    return currentSize;
}