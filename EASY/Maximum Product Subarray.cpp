/*
Problem:
Given an integer array, find the maximum product of any subarray.

Approach:
For arrays with only positive elements, we track the maximum
running product at each index. With zeros and negatives:
- Zeros: Reset the product (any subarray with zero has product = 0)
- Negative numbers: We track both min and max products, as a negative
    number can turn a minimum into a maximum when multiplied

Algorithm:
1. Initialize currMin, currMax, and maxProd to first element
2. For each index i from 1 to N-1:
     - Update currMax = max(arr[i], currMax*arr[i], currMin*arr[i])
     - Update currMin = min(arr[i], currMax*arr[i], currMin*arr[i])
     - Update maxProd with maximum value
3. Return maxProd as result
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <string>
using namespace std;

// function to find the product of max product subarray
int maxProduct(vector<int> &arr)
{
    int n = arr.size();

    // max product ending at the current index
    int currMax = arr[0];

    // min product ending at the current index
    int currMin = arr[0];

    // Initialize overall max product
    int maxProd = arr[0];

    // Iterate through the array
    for (int i = 1; i < n; i++)
    {

        // Temporary variable to store the maximum product ending
        // at the current index
        int temp = max({arr[i], arr[i] * currMax,
                        arr[i] * currMin});

        // Update the minimum product ending at the current index
        currMin = min({arr[i], arr[i] * currMax,
                       arr[i] * currMin});

        // Update the maximum product ending at the current index
        currMax = temp;

        // Update the overall maximum product
        maxProd = max(maxProd, currMax);
    }
    return maxProd;
}
