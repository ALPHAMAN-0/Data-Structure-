/*
PROBLEM:
Given an array of n elements, find minimum operations 
to make all elements equal. One operation: increment 
any element by k. If impossible, return -1.

APPROACH:
1. Maximum value becomes our target
2. For each element: (max - element) must be 
    divisible by k, otherwise impossible
3. Count operations = sum of (max - element)/k 
    for all elements
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <cmath>
#include <unordered_map>


using namespace std;

int minOps(vector<int>& arr, int k) {
  
    int maxVal = *max_element(arr.begin(), arr.end());
    int res = 0;

    for (int x : arr) {
      
        // check if element can be made equal to max
        // if not, return -1
        if ((maxVal - x) % k != 0)
            return -1;

        // else, update res for required operations
        res += (maxVal - x) / k;
    }

    return res;
}

int main() {
    vector<int> arr = { 21, 33, 9, 45, 63 };
    int k = 6;

    cout << minOps(arr, k);
    return 0;
}
