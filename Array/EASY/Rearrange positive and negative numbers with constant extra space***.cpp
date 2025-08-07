/*
Problem:
Given an array of integers, arrange them such that all negative integers 
appear before all positive integers while maintaining the order of appearance.
No additional data structures allowed.

Approach:
We can do in-place merging without using auxiliary space.

Let's define:
- Ln: negative part of left sub-array
- Lp: positive part of left sub-array
- Rn: negative part of right sub-array
- Rp: positive part of right sub-array

Steps to convert [Ln Lp Rn Rp] to [Ln Rn Lp Rp]:
1. Reverse Lp and Rn:
    [Ln Lp Rn Rp] -> [Ln Lp' Rn' Rp]
    
2. Reverse [Lp' Rn']:
    [Ln Lp' Rn' Rp] -> [Ln Rn Lp Rp]
    
This gives us all negatives (Ln Rn) followed by all positives (Lp Rp).
*/
#include <iostream>
#include <vector>
using namespace std;

// Function to reverse the subarray arr[l...r]
void reverse(vector<int>& arr, int l, int r) {
    if (l < r) {
        swap(arr[l], arr[r]);
        reverse(arr, ++l, --r);
    }
}

// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(vector<int>& arr, int l, int m, int r) {
    int i = l;
    int j = m + 1;

  	// find starting index of positive part in the 
  	// first half i.e., find starting index of Lp
    while (i <= m && arr[i] < 0)
        i++;

    // find ending index of negative part in the 
  	// first second i.e., find ending index of Rn
    while (j <= r && arr[j] < 0)
        j++;
	j--;

    // reverse positive part of
    // left sub-array (arr[i..m])
    reverse(arr, i, m);

    // reverse negative part of
    // right sub-array (arr[m+1..j])
    reverse(arr, m + 1, j);

    // reverse arr[i..j]
    reverse(arr, i, j);
}

// Function to Rearrange positive and negative
// numbers in a array
void rearrange(vector<int>& arr, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        // Sort first and second halves
        rearrange(arr, l, m);
        rearrange(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}
