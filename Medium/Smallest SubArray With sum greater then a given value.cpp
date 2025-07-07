/*
Problem:
Given an array arr[] of integers and a number x,
find the smallest subarray with sum strictly greater than x.

Approach 1:
Store prefix sums and use binary search.
- Compute prefix sum array preSum[]
- For each index i, find lower bound for (x + preSum[i])
    in range [i+1, n]
- If found and sum > x, update result if smaller

Approach 2:
Use two-pointer sliding window technique.
- Expand window by adding elements until sum > x
- Shrink window from start while maintaining sum > x
- Keep track of minimum valid window length
*/

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

// Function to find smallest subarray with sum greater than x using sliding window easy expected apprach
int smallestSubWithSum(int x, vector<int>& arr) {

    int i = 0, j = 0;
    int sum = 0;
    int ans = INT_MAX;
    
    while (j < arr.size()) {
        
        // Expand window until sum > x 
        // or end of array reached
        while (j < arr.size() && sum <= x) {
            sum += arr[j++];
        }
        
        // If we reached end of array and sum 
        // still <= x, no valid subarray exists
        if (j == arr.size() && sum <= x) break;
        
        // Minimize window from start 
        // while maintaining sum > x
        while (i < j && sum - arr[i] > x) {
            sum -= arr[i++];
        }
        
        ans = min(ans, j-i);
        
        // Remove current start 
        // element and shift window
        sum -= arr[i];
        i++;
    }
    
    // Return 0 if no valid subarray
    // found, else return min length
    if (ans == INT_MAX) return 0;
    return ans;
}

// use prefix sum and binary search (hard approach better approach)
int smallestSubWithSum(int x, vector<int> &arr) {
    int n = arr.size();

    int res = INT_MAX;
    vector<int> preSum(n + 1, 0);

    // Compute the prefix sums
    for (int i = 1; i <= n; i++)
        preSum[i] = preSum[i - 1] + arr[i - 1];

    // Iterate through each starting index
    for (int i = 1; i <= n; i++) {

        // Target sum for current subarray
        int toFind = x + preSum[i - 1];

        // Find the first prefix sum > target
        auto bound = lower_bound(preSum.begin(), preSum.end(), toFind);

        if (bound != preSum.end() && *bound != toFind) {
            int len = bound - (preSum.begin() + i - 1);
            res = min(res, len);
        }
    }

    // If subarray does not exists
    if (res == INT_MAX)
        return 0;

    return res;
}
