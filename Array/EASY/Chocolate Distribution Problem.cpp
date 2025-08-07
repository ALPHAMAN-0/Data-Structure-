/*
Chocolate Distribution Problem
-----------------------------

Problem:
- Given array arr[] of n integers where arr[i] = chocolates in ith packet
- Need to distribute packets to m students
- Each student gets exactly one packet
- Goal: Minimize difference between max and min chocolates given

Approach:
1. Sort the array of chocolate packets
2. Use sliding window of size m (number of students)
3. For each possible window, calculate max-min difference
4. Track and return the minimum difference found

Time Complexity: O(n log n) due to sorting
Space Complexity: O(1) as we use only variables
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

int findMinDiff(vector<int> &arr, int m) {
	int n = arr.size();
  
    // Sort the given packets
    sort(arr.begin(), arr.end());

    int minDiff = INT_MAX;

    for (int i = 0; i + m - 1 < n; i++) {
      	
      	// calculate difference of current window
        int diff = arr[i + m - 1] - arr[i];
      
      	// if current difference is smaller
      	// then update the minimum difference
        if (diff < minDiff)
        	minDiff = diff;
    }
    return minDiff;
}
