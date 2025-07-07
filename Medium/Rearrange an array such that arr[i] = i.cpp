/*
PROBLEM:
Given an array of length n with values from 0 to n-1, where missing
elements are marked as -1, rearrange it so that arr[i] = i or -1
if i is not present.

APPROACH:
1. Iterate through the array
2. If arr[i] equals i, skip to next element
3. If arr[i] is not -1, swap it to its correct position:
    - Put arr[i] at index arr[i] by swapping arr[i] with arr[arr[i]]
    - Don't increment i to check the new element that was swapped in
4. Continue until either -1 is encountered or element is correctly placed

TIME COMPLEXITY: O(n) as each element is placed at most once
*/
#include <iostream>
#include <vector>
using namespace std;
void modifyArray(vector<int>& arr) {
    int i = 0;
    while (i < arr.size()) {
      
        // Swap if the element arr[i] is not at arr[arr[i]]
        if (arr[i] != -1 && arr[i] != arr[arr[i]]) {
            swap(arr[i], arr[arr[i]]);
          
        } else {
          
            // Increment i if element is at its correct position
            i++;
        }
    }
}
