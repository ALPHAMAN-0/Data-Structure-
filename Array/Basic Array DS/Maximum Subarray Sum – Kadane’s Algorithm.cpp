/*
PROBLEM:
Find a contiguous subarray with the largest sum in an array and return this sum.

KADANE'S ALGORITHM:
This algorithm finds the maximum subarray sum in O(N) time by making a single
pass through the array.

APPROACH:
1. For each position, we decide whether to:
    - Add current element to the existing subarray
    - Start a new subarray from current element

2. At each element, we calculate:
    maxEndingHere = max(maxEndingHere + currentElement, currentElement)
    
3. We keep track of the maximum value of maxEndingHere seen so far

KEY IDEA:
If maxEndingHere becomes negative, it's better to start a new subarray.
Otherwise, continue extending the current subarray.
*/
#include <iostream>
#include <vector>

using namespace std;
int maxSubarraySum(vector<int> &arr) {
    int res = arr[0];
    int maxEnding = arr[0];

    for (int i = 1; i < arr.size(); i++) {
      
        // Find the maximum sum ending at index i by either extending 
        // the maximum sum subarray ending at index i - 1 or by
        // starting a new subarray from index i
        maxEnding = max(maxEnding + arr[i], arr[i]);
      
        // Update res if maximum subarray sum ending at index i > res
        res = max(res, maxEnding);
    }
    return res;
}
