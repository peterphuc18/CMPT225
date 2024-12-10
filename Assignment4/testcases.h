#pragma once

#include <iostream>
#include <ostream>
#include <cassert>
#include <vector>
#include <algorithm>

#include "debugInfo.h"
#include "HeapT.h"
#include "largestm.h"

/*
 * Created 2024-11-03 1:58pm
 * Test Cases for Assignment 4 - Brandon Tang
 * Notes: There are three functions, testPartOne, testPartTwo, and testExceptions
 * testPartOne will test the heap functionality
 * testPartTwo will test the largestm functionality
 * testExceptions will test that each exception is handled properly. Each testcase should be tested manually, as an error is thrown.
 */

void testFunction(const int output, const int expected, const float testNo, const std::string details){
	std::cout<<"========================="<<std::endl;
	std::cout<<"Running Test: "<<testNo<<std::endl;
	if (output == expected) {
		std::cout<<"Test "<<testNo<<" Passed!"<<std::endl;
		std::cout<<"========================="<<std::endl;
		return;
	}
	std::cout << "Expected Output: "<<expected<<std::endl;
	std::cout << "Your Code Outputted: "<<output<<std::endl;
	std::cout << std::endl;

	// print test info
	std::cout<<details<<std::endl;
	assert(expected == output);
}

void testFunction(const double output, const double expected, const float testNo, const std::string details){
	std::cout<<"========================="<<std::endl;
	std::cout<<"Running Test: "<<testNo<<std::endl;
	if (output == expected) {
		std::cout<<"Test "<<testNo<<" Passed!"<<std::endl;
		std::cout<<"========================="<<std::endl;
		return;
	}
	std::cout << "Expected Output: "<<expected<<std::endl;
	std::cout << "Your Code Outputted: "<<output<<std::endl;
	std::cout << std::endl;

	// print test info
	std::cout<<details<<std::endl;
	assert(expected == output);
}

// Example Test Function
void simpleTest()
{
    // Int Heap Tests
    HeapT<int> pq1(4);

    // Insert elements into the heap
    pq1.insert(3);
    pq1.insert(1);
    pq1.insert(42);

    // Peek at the root of the heap
    int peek = pq1.peek();
    std::cout << "pq1 root = " << peek << std::endl; // 1

    // Remove the root element
    pq1.remove();
    std::cout << "pq1 root = " << pq1.peek() << std::endl; // 3
    std::cout << "pq1 size = " << pq1.size() << std::endl; // 2

    // Copy constructor test
    HeapT<int> pq2(pq1);
    pq2.insert(-42);

    // Merge test
    HeapT<int> pq3 = pq1.merge(pq2); // Should contain duplicates
    std::cout << "pq3 size = " << pq3.size() << std::endl; // 5
    std::cout << "pq3 root = " << pq3.peek() << std::endl; // -42

    // Insert more elements to fill the heap
    pq1.insert(5);
    pq1.insert(0);
    std::cout << "pq1 size after inserting more elements = " << pq1.size() << std::endl; // 4
    std::cout << "pq1 root after inserting more elements = " << pq1.peek() << std::endl; // 0

    // Test removing all elements
    while (pq1.size() > 0)
    {
        std::cout << "Removing root: " << pq1.remove() << ", pq1 size = " << pq1.size() << std::endl;
    }
    // Heap should be empty now
    try
    {
        pq1.peek();
    }
    catch (const std::runtime_error& e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl; // "Heap is empty"
    }

    // Assignment operator test
    HeapT<int> pq4(5);
    pq4.insert(10);
    pq4.insert(15);
    pq4 = pq2;
    std::cout << "pq4 root after assignment = " << pq4.peek() << std::endl; // -42
    std::cout << "pq4 size after assignment = " << pq4.size() << std::endl; // 3

    // Test merge with empty heap
    HeapT<int> pq5(5);
    HeapT<int> pq6 = pq5.merge(pq4);
    std::cout << "pq6 size after merging with empty heap = " << pq6.size() << std::endl; // 3
    std::cout << "pq6 root after merging with empty heap = " << pq6.peek() << std::endl; // -42
}

void testPartOne() {
	HeapT<int> pq1(8);
	pq1.insert(3); // insert 3
	pq1.insert(4); // insert 4
	pq1.insert(1); // insert 1 : BECOMES THE ROOT
	
	testFunction(pq1.peek(), 1, 1.0f, testCaseOne);
	
	HeapT<int> pq2(8);
	pq2.insert(9);
	pq2.insert(2);
	pq2.insert(5);

	testFunction(pq2.peek(), 2, 2.0f, testCaseTwo);

	HeapT<int> pq3(pq2); // make sure that this is a deep copy

	pq3 = pq1;

	for(int i = 0; i < pq1.size(); i++) assert(pq3.peek() == pq1.peek());

	HeapT<double> pq4(8);
	std::vector<double> pq_vec = {10.40, 9.60, 6.60, 7.20, 8.30, 9.40, 10.60, 1.10};
	for(auto &i : pq_vec) {
		pq4.insert(i);
	}

	std::sort(pq_vec.begin(), pq_vec.end(), [](double a, double b) { return a < b; });

	for(int i = 0; i < pq_vec.size(); i++) {
		testFunction(pq4.remove(), pq_vec[i], 3.0f + (i * 0.1), testCaseThree);
	}

	HeapT<int> pq5 = pq1.merge(pq2);
	std::cout<<pq5.size()<<std::endl;
	std::vector<int> expected_values = {1,2,3,4,5,9};

	for(int i = 0; i < expected_values.size(); i++) {
		testFunction(pq5.remove(), expected_values[i], 4.0f + (i * 0.1), testCaseFour);
	}	

	std::cout<<"All tests for part one passed!"<<std::endl;
}

// simple test
void simpleTestlargestm()
{
// largestm test (comment out if just testing HeapT)
    std::vector<int> v = {10,5,2,8,6,4,3,9,1};
    std::vector<int> maxm = largestm<int>(v, 4);
    std::cout << "Largest m values: ";
    for (int val : maxm) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}

const int V_MAX_1_SIZE = 3;
const int V_MAX_2_SIZE = 8;

void testPartTwo() {
	HeapT<int> pq1(8);
	std::vector<int> v = {6,5,4,3,7,8,9,10};
	for(auto &i : v) pq1.insert(i);

	std::vector<int> v_max1 = largestm(v, 3);
	std::vector<int> v_max2 = largestm(v, 1000);

	std::sort(v.begin(), v.end(), [](int a, int b){ return a > b; }); // sorts the list in descending order

	for(int i = 0; i < V_MAX_1_SIZE; i++) {
		testFunction(v_max1[i], v[i], 4.0f + (i * 0.1), testCaseFive);
	}

	for(int i = 0; i < V_MAX_2_SIZE; i++) {
		testFunction(v_max2[i], v[i], 5.0f + (i * 0.1), testCaseSix);
	}

	std::cout<<"All tests for part two passed!"<<std::endl;
}

// Now testing edge cases

void testRemovingEmpty() {
	HeapT<int> pq(8);
	pq.insert(1);
	pq.remove();
	pq.remove(); // should throw error
}

void testFull() {
	HeapT<int> pq(2);
	pq.insert(1);
	pq.insert(2);
	pq.insert(3); // should throw error
}

void testPeekingEmpty() {
	HeapT<int> pq(2);
	pq.peek(); // should throw error
}

/*
// Test inserting elements in sorted order
void testSortedInsertion() {
    std::cout << "\nTesting sorted insertion (ascending order)..." << std::endl;

    HeapT<int> heap(10);
    for (int i = 1; i <= 5; ++i) {
        heap.insert(i);
    }

    std::cout << "Heap after insertions: " << heap << std::endl;
    // Expected Output: Heap after insertions: 1 2 3 4 5 (min-heap property)

    // Check remove
    std::cout << "Remove root: " << heap.remove() << std::endl;
    std::cout << "Heap after removal: " << heap << std::endl;
    // Expected Output: Remove root: 1
    // Expected Output: Heap after removal: 2 4 3 5
}

// Test inserting elements in reverse order
void testReverseOrderInsertion() {
    std::cout << "\nTesting reverse order insertion..." << std::endl;

    HeapT<int> heap(10);
    for (int i = 5; i >= 1; --i) {
        heap.insert(i);
    }

    std::cout << "Heap after insertions: " << heap << std::endl;
    // Expected Output: Heap after insertions: 1 2 4 5 3

    // Check remove
    std::cout << "Remove root: " << heap.remove() << std::endl;
    std::cout << "Heap after removal: " << heap << std::endl;
    // Expected Output: Remove root: 1
    // Expected Output: Heap after removal: 2 3 4 5
}
*/
