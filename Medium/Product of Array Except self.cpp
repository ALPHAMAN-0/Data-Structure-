/*
Problem: Product of Array Except Self
------------------------------------------

Given an array arr[] of n integers, construct a 
product array res[] (of the same size) such that 
res[i] is equal to the product of all the elements 
of arr[] except arr[i].

Approach:
------------------------------------------
Handle two cases separately:

1. No zeros in array:
    - Product at any index can be calculated by 
      dividing total product by the current element

2. With zeros:
    - One zero: Only the zero index will have a 
      non-zero product (product of all other elements)
    - Multiple zeros: All products will be zero
*/
#include <iostream>
#include <vector>
using namespace std;

// Function to calculate the product of all elements 
// except the current element
vector<int> productExceptSelf(vector<int> &arr) {
    int zeros = 0, idx = -1;
    int prod = 1;

    // Count zeros and track the index of the zero
    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] == 0) {
            zeros++;
            idx = i;
        } else {
            prod *= arr[i];
        }
    }

    vector<int> res(arr.size(), 0);

    // If no zeros, calculate the product for all elements
    if (zeros == 0) {
        for (int i = 0; i < arr.size(); i++)
            res[i] = prod / arr[i];
    }
    // If one zero, set product only at the zero's index
    else if (zeros == 1)
        res[idx] = prod;

    return res;
}
