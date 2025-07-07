/*
PROBLEM: Find the Missing Number

Description:
Given an array of size n-1 with distinct integers from 1 to n,
find the missing number.

APPROACHES:

1. Sum Method:
    - Calculate sum of first n natural numbers: n(n+1)/2
    - Find sum of array elements
    - Missing number = Expected sum - Actual sum

2. XOR Method:
    - XOR all numbers from 1 to n
    - XOR all elements in the array
    - The result is the missing number (since x^x=0)
*/
#include <iostream>
#include <vector>
using namespace std;

int missingNumberXOR( vector<int>& arr) {
    int n= arr.size()+1;
    int xor1 = 0, xor2 = 0;

    // XOR all array elements
    for (int i = 0; i < n - 1; i++) {
        xor2 ^= arr[i];
    }

    // XOR all numbers from 1 to n
    for (int i = 1; i <= n; i++) {
        xor1 ^= i;
    }

    // Missing number is the XOR of xor1 and xor2
    return xor1 ^ xor2;
}

int missingNumber(vector<int> &arr) {

    int n = arr.size() + 1;
  
    // Calculate the sum of array elements
    int sum = 0;
    for (int i = 0; i < n - 1; i++) {
        sum += arr[i];
    }

    // Calculate the expected sum
    int expectedSum = (n * (n + 1)) / 2;

    // Return the missing number
    return expectedSum - sum;
}
