/*
Problem:
Given an integer array arr[], find the sum of all sub-arrays of the given array.

Approach:
There's a pattern in how many times each element appears in all subarrays.

Example:
arr[] = [1, 2, 3], n = 3
All subarrays: [1], [1,2], [1,2,3], [2], [2,3], [3]

Counting appearances:
- First element (1) appears 3 times
- Second element (2) appears 4 times
- Third element (3) appears 3 times

Why? Each element arr[i] appears in:
1. Subarrays starting with arr[i]: (n-i) subarrays
2. Subarrays where arr[i] isn't first: (n-i)*i subarrays

Total appearances: (n-i)(i+1)

Formula:
Sum = Σ arr[i] * (i+1) * (n-i) for i=0 to n-1

Calculation for [1,2,3]:
1*(1)*(3) + 2*(2)*(2) + 3*(3)*(1)
= 3 + 8 + 9
= 20
*/
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;
 
int subarraySum(vector<int>&arr) {
    
     int n=arr.size();
      int result = 0;

    // computing sum of subarray using formula
    for (int i = 0; i < n; i++)
        result += (arr[i] * (i + 1) * (n - i));

    // return all subarray sum
    return result;
}
int main() {
    vector<int>arr = { 1, 2, 3 };
    int n = arr.size();
    cout <<subarraySum(arr);
    return 0;
}
