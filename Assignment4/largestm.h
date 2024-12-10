// cmpt225 a4 Heaps (Part2):
// Author: Peter Phuc
// Date: November 2024

#pragma once // include guard

#include <vector>
#include <iostream>

#include "HeapT.h"

template <typename T>
std::vector<T> largestm(const std::vector<T>& input, int m)
{
    // if m is greater than or equal to the size of the input vector, return all elements in descending order
    if (m >= input.size())
    {
        std::vector<T> result = input;
        HeapT<T> heap(result.size());
        for (const T& value : result)
        {
            heap.insert(value);
        }

        std::vector<T> sortResult;
        while (heap.size() > 0)
        {
            sortResult.push_back(heap.remove());
        }
        return std::vector<T>(sortResult.rbegin(), sortResult.rend());
    }

    // create a min-heap of size m
    HeapT<T> minHeap(m);
    for (int i = 0; i < m; i++)
    {
        minHeap.insert(input[i]);
    }

    // process remaining elements in the input vector
    for (int i = m; i < input.size(); i++)
    {
        if (input[i] > minHeap.peek())
        {
            minHeap.remove();
            minHeap.insert(input[i]);
        }
    }

    // extract elements from the heap and store them in descending order
    std::vector<T> result;
    while (minHeap.size() > 0)
    {
        result.push_back(minHeap.remove());
    }
    return std::vector<T>(result.rbegin(), result.rend());
}