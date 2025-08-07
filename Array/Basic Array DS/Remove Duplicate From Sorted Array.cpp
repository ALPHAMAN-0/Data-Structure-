/*
Problem: Remove Duplicates from Sorted Array
----------------------------------------
Given a sorted array, rearrange it so all distinct elements 
appear at the beginning in order, and return the length of 
this distinct subarray.

Note: Elements after the distinct ones can be in any order.

Approach:
- Since array is sorted, duplicates are consecutive
- Use a pointer (idx) to track where to place next unique element
- Iterate through array, comparing each element with previous one
- If different, place at position idx and increment idx
- Return idx as length of distinct subarray

Time Complexity: O(n)
Space Complexity: O(1)
*/
#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int>& arr) {
    int n = arr.size();
    if (n <= 1)
        return n;

  	// Start from the second element
    int idx = 1; 
  
    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[i - 1]) {
            arr[idx++] = arr[i];
        }
    }
    return idx;
}

int main() {
    vector<int> arr = {1, 2, 2, 3, 4, 4, 4, 5, 5};
    int newSize = removeDuplicates(arr);
    for (int i = 0; i < newSize; i++) 
        cout << arr[i] << " ";
    return 0;
}
