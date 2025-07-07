/*
Problem:
Given an array and a number k, find the largest sum of contiguous 
subarray in the modified array which is formed by repeating the 
given array k times.

Approach:
An efficient solution is to run a loop on the same array and use 
modular arithmetic to move back to beginning after reaching the 
end of array.

Below is the implementation:
*/
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

// Returns sum of maximum sum subarray created
// after concatenating a[0..n-1] k times.
int maxSubArraySumRepeated(vector<int>& arr, int k) {
    int n = arr.size();
    int maxSoFar = INT_MIN, maxEndingHere = 0;

    for (int i = 0; i < n * k; i++) {
      
        // Use modular arithmetic to get the next element
        maxEndingHere += arr[i % n];

        maxSoFar = max(maxSoFar, maxEndingHere);

        if (maxEndingHere < 0)
            maxEndingHere = 0;
    }
    return maxSoFar;
}
