/*
GENERATING ALL SUBARRAYS

Problem:
Given an array arr[], generate all possible subarrays of the array.

Algorithm:
1. Use two pointers 'start' and 'end' to define the subarray boundaries
2. For each starting position (start = 0 to n-1):
    a. For each ending position (end = start to n-1):
        i. Print the subarray from index 'start' to 'end'
3. This generates all possible subarrays from the original array

Time Complexity: O(n²) where n is the length of the array
Space Complexity: O(1) as we only use two pointer variables
*/
// Work In hand
#include <iostream>
#include <vector>
using namespace std;

// Recursive function to print all possible subarrays for given array
void printSubArrays(vector<int>& arr, int start, int end) {

    // Stop if we have reached the end of the array
    if (end == arr.size())
        return;

    // Increment the end point and reset the start to 0
    else if (start > end)
        printSubArrays(arr, 0, end + 1);

    // Print the subarray and increment the starting point
    else {
        for (int i = start; i <= end; i++)  
            cout << arr[i] << " ";
        cout << endl;
        printSubArrays(arr, start + 1, end);  
    }
}

int main() {
    vector<int> arr = {1, 2, 3};
    printSubArrays(arr, 0, 0);
    return 0;
}   
