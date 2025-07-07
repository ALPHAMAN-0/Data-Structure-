/*
    Problem : Given an array arr[] of size n-1 with distinct integers in the range of [1, n]. 
    This array represents a permutation of the integers from 1 to n with one element missing. Find the missing element in the array.
    
    Solve Way
    1)The idea is to use an auxiliary array hash[] to store the frequency of each element in the given array arr[]. The number with frequency 0 is the missing number.

    2)The sum of the first n natural numbers is given by the formula (n * (n + 1)) / 2. The idea is to compute this sum and subtract the sum of all elements in the array from it to get the missing number.
    
    3)XOR of a number with itself is 0 i.e. x ^ x = 0 and the given array arr[] has numbers in range [1, n]. This means that the result of XOR of first n natural numbers with the XOR of all the array elements will be the missing number. To do so, calculate XOR of first n natural numbers and XOR of all the array arr[] elements, and then our result will be the XOR of both the resultant values.


*/
// C++ program to find the missing number

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
using namespace std;
 
int missingNumber( vector<int>& arr) {
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

 
int main() {
    vector<int> arr = { 1, 2, 3, 5 };
    int res = missingNumber( arr);
    cout << res;
    return 0;
}
