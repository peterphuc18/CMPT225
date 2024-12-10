// CMPT 225 assignment 3 
// Author: Peter Phuc
// Date: October 2024

#include <iostream>
#include <string>

using namespace std;

// Q1
//PARAM: arr is array to print the Cartesian product of, n is size of arr
void cartesianProduct(int arr[], int n, int& ops)
{
    int i = 0; //+1
    ops = 1;

    while (i < n) //+1
    { 
        int j = 0; //+1
        ops += 2;

        while (j < n) //+1
        { 
            cout << "{" << arr[i] << "," << arr[j] << "}"; //+1
            j++; //+1
            cout << " "; // +1
            ops += 4;
        }
        ops++; // terminating while comparison

        cout << endl; //+1
        i++; //+1
        ops += 2;
    }
    ops++; // terminating while comparison
}

// Q2
void triangle(int x, int& ops)
{
    int i = 0; //+1
    ops = 1;
    
    while (i < x) //+1
    {
        int j = 0;
        ops += 2;

        while (j <= i) //+1
        {
            cout << j << " "; //+1
            j++; //+1
            ops += 3;
        }
        ops++; // terminating while comparison

        cout << endl; //+1
        i++; //+1
        ops += 2;
    }
    ops++; // terminating while comparison

    while (i > 0) //+1
    {
        i--; //+1
        int j = 0; //+1
        ops += 3;
        
        while (j <= i) //+1
        {
            cout << j << " "; //+1
            j++; //+1
            ops += 3;
        }
        ops++; // terminating while comparison

        cout << endl; //+1
        ops += 1;
    }
    ops++; // terminating while comparison
}

// Q3
// Returns the index of a 1d array representing a matrix
// given row (r) and column (c) values
int rcIndex(int r, int c, int columns, int& ops)
{
    ops += 1; // for return in function
    return r * columns + c; //+1
}

//PRE: m represents a square matrix of size rows * rows
// PARAM: rows represents the number of both rows and columns
// POST: Returns a pointer to an array (matrix) of the same size as m
// NOTE: values are indexed r0c0,r0c1,…,r0cn-1,r1c0,…
int* matrixSelfMultiply(int* m, int rows, int& ops)
{
    // Create result array
    int columns = rows; //+1
    int* result = new int[rows * columns]; //+1
    int r = 0; //+1
    ops = 3;
    
    while (r < rows) //+1
    {
        int c = 0; //+1
        ops += 2;
        
        while (c < columns) // columns = rows //+1
        { 
        int next = 0; //+1
        int iNext = 0; //+1
        ops += 3;
        
        while (iNext < rows) //+1
        {
            next += m[rcIndex(r, iNext, columns, ops)] * m[rcIndex(iNext, c, columns, ops)]; //+1
            iNext++; //+1
            ops += 3;
        }
        ops++; // terminating while comparison

        result[rcIndex(r, c, columns, ops)] = next; //+1
        c++; //+1
        ops += 2;
        }
        ops++; // terminating while comparison
        
        r++; //+1
        ops += 1;
    }
    ops++; // terminating while comparison
    return result;
}

// Q4
// PARAM: arr is array to be sorted, n is size of array, i should initially = 0
// selection sort
void ssort(int arr[], int n, int i, int& ops)
{
    if (i < n-1) // Find and swap smallest remaining //+1
    {
        int next = i + 1; //+1
        int smallest = i; //+1
        ops += 3;
        
        while (next < n) //+1
        {
            ops += 1; // for while
            if (arr[next] < arr[smallest]) //+1 
            {
                smallest = next; //+1
                ops += 1;
            }
            ops++; // terminating if comparison
            
            next++; //+1
            ops += 1;
        }
        ops++; // terminating while comparison
        
        // Swap i with smallest
        int temp = arr[i]; //+1
        arr[i] = arr[smallest]; //+1
        arr[smallest] = temp; //+1
        ops += 3;

        ssort(arr, n, i+1, ops); //ops++
    }
    else
    {
        ops++; // if state false
    }
}

// Q5
// PRE: n is a power of 2 greater than zero.
// PRE: Initial call should be to i = 0
// e.g. pattern(8, 0)
void pattern(int n, int i, int& ops)
{
    if (n > 0) //+1
    {
        pattern(n/2, i, ops); //ops++
        
        // Print i spaces
        cout << string(i, ' '); //+3
        
        //A loop to print n asterisks, each one followed by a space
        int ast = 0; //+1
        ops += 6; 

        while (ast < n) //+1
        {
            cout <<"* "; //+1
            ast++; //+1
            ops += 3;
        }
        ops++; // terminating while comparison

        cout << endl; //+1
        i += n; //+1
        ops += 2;
        pattern(n/2, i, ops); //ops++
    }
    else
    {
        ops++; // if state false
    }
}

// Q6
// Desc: Linear search. Reports position if found, else -1
// Post: Elements unchanged
int lsearch(int arr[], unsigned int len, int target, int& ops) 
{
    if (len == 0) //+1
    {
        ops++; // if state true
        return -1;
    }
    ops++; // if state false

    if (arr[0] == target) //+1
    {
        ops++; // if state true
        return 0;
    }
    ops++; // if state false
    
    if (lsearch(arr+1, len-1, target, ops) == -1) //+2 
    {
        ops += 2; // if and lsearch
        return -1;
    } 
    else 
    {
        ops += 2; // if state false and lsearch
        return 1 + lsearch(arr+1, len-1, target, ops); //+2
    }
} // lsearch

// Q7
unsigned pow(unsigned int base, unsigned int exp, int& ops) 
{
    unsigned int ret = 1; //+1
    ops = 1;
    
    while (exp > 0) //+1
    {
        ops += 1;
        if (exp & 1) //+1
        {
            ret *= base; //+1
            ops += 1;
        }
        ops++; // terminating if comparison

        exp >>= 1; //+1
        base = base * base; //+1
        ops += 2;
    }
    ops++; // terminating while comparison
    return ret;
} // pow

