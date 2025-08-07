/*
Problem:
Given an array arr[] of integers, rearrange them such that:
- All negative integers appear before all positive integers
- The order of appearance should be maintained
- No additional data structures allowed (e.g., hash tables, arrays)

Approach:
Let's represent the array as [Ln Lp Rn Rp] where:
- Ln: Negative numbers in the left subarray
- Lp: Positive numbers in the left subarray
- Rn: Negative numbers in the right subarray
- Rp: Positive numbers in the right subarray

Our goal is to transform [Ln Lp Rn Rp] to [Ln Rn Lp Rp].

Steps:
1. Reverse Lp and Rn separately:
    - [Lp] becomes [Lp'] (reversed)
    - [Rn] becomes [Rn'] (reversed)
    - Result: [Ln Lp' Rn' Rp]

2. Reverse the entire segment [Lp' Rn']:
    - This gives us [Rn Lp]
    - Final result: [Ln Rn Lp Rp]
*/
#include <iostream>
#include <vector>
using namespace std;


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
