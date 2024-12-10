//main.cpp
#include "a3.h"
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

void cartesianProductTest();
void triangleTest();
void matrixSelfMultiplyTest();
void ssortTest();
void patternTest();
void lsearchTest();
void powTest();

int main(){
    //TODO: barometer ops + writing PDF
    cartesianProductTest();
    triangleTest();
    matrixSelfMultiplyTest();
    ssortTest();
    patternTest();
    lsearchTest();
    powTest(); 
}   

void cartesianProductTest(){
    cout << "--------------\n";
    cout << "Cartesian Product Test\n";
    int arr[] = {1, 2, 3, 4, 5};
    int n = 5;
    int cost = 0;
    cartesianProduct(arr, n, cost);
    cout << endl << "cost = " << cost;
    cout << endl << "t(cartProd)) = " << 4*(n*n) + 5*(n) + 2;
    cout << endl << "--------------\n\n";
}

void triangleTest(){
    cout << "--------------\n";
    cout << "Triangle Test\n";
    int n = 5;
    int cost = 0;
    triangle(n, cost);
    cout << endl << "cost = " << cost;
    cout << endl << "t(triangle) = " << (6*(n*n))/2 + 13*(n) + 3;
    cout << endl << "--------------\n\n";
}

void matrixSelfMultiplyTest(){
    cout << "--------------\n";
    cout << "Matrix Self Multiply Test";
    int rows = 6;
    int m[] = {1, 2, 3, 4, 5, 6};
    //int* m = new int[rows*rows];
    int cost = 0;
    matrixSelfMultiply(m, rows, cost);
    cout << endl << "cost = " << cost;
    cout << endl << "t(sqmatrix) = " << 5*(rows*rows*rows) + 7*(rows*rows) + 4*(rows) + 4;
    cout << endl << "--------------\n\n";
}

void ssortTest(){
    cout << "--------------\n";
    cout << "SSort Test";
    //int arr[] = {20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1};
    int arr[] = {4,3,2,1};
    int n = 4; //array size
    int i = 0; //initially = 0
    int cost = 0;
    ssort(arr, n, i, cost);
    cout << endl << "cost = " << cost;
    if(n % 2 == 0){
        cout << endl << "t(ssort-even) = " << 1.75*(n*n) + 5.5*(n) - 6;
    }
    else{
        cout << endl << "t(ssort-odd) = " << 1.75*(n*n) + 5.5*(n) - 6.25;
    }
    cout << endl << "--------------\n\n";
}

void patternTest(){
    cout << "--------------\n";
    cout << "Pattern Test\n";
    int n = 8; //power of 2 greater than 0
    int i = 0; //initially = 0
    int cost = 0;
    pattern(n, i, cost);
    cout << endl << "cost = " << cost;
    cout << endl << "t(pattern) = " << 3*n*(log2(n)) + 23*n - 9;
    cout << endl << "--------------\n\n";
}

void lsearchTest(){
    cout << "--------------\n";
    cout << "LSearch Test\n";
    int arr[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    // unsigned int len = 20; //array length, n
    // int target = len; //target=len to simplfy worst-case testing
    // int cost = 0;
    // lsearch(arr, len, target, cost);
    // cout << endl << "cost = " << cost;
    // cout << endl << "t(lsearch) = " << 3*(pow(2, len)) - len/2;
    // cout << endl << "--------------\n";

    for(int i = 1;i <= 20;i++){
        unsigned int len = i; //array length, n
        int target = len; //target=len to simplfy worst-case testing
        int cost = 0;
        lsearch(arr, len, target, cost);

        cout << "i = " << i;
        cout << endl << "cost = " << cost;
        cout << endl << "t(lsearch) = " << 3*(pow(2, len)) - 4;
        cout << endl << "--------------\n\n";
    }
}

void powTest(){
    cout << "--------------\n";
    cout << "Pow Test";
    cout << endl;
    for(int i = 1;i <= 15;i++){
        unsigned int base = 2;
        unsigned int exp = i;
        int cost = 0;
        pow(base, exp, cost);
        cout << "i = " << i;
        cout << endl << "cost = " << cost;
        cout << endl << "t(pow) = " << floor(6*log(exp) + 7);
        //5.6*log(exp) + 6.8), original (decimal) form
        //log = ln, within <cmath>
        cout << endl << "--------------\n";
    }
    // unsigned int base = 2;
    // unsigned int exp = 3;
    // int cost = 0;
    // pow(base, exp, cost);
    // cout << endl << "cost = " << cost;
    // cout << endl << "t(pow) = " << log2(exp) + 1;
    // cout << endl << "--------------\n";
}