/*
Problem statement:
We are given an array that contains 1 to n elements,
our task is to sort this array in an efficient way.
We are not allowed to simply copy the numbers from 1 to n.

Approach:
We can use counting sort to achieve this in linear time.
Note that the counting sort keeps array values only
and does not copy values from 1 to n.

Efficient Approach 1 - O(n) Time and O(1) Space
Follow the steps mentioned below to solve the problem.
The idea is based on Cycle Sort algorithm:

1. Traverse the array 
2. If the element is at its correct position, do not do anything
3. Else swap the element with the element at its correct position
*/
#include <iostream>
#include <vector>
using namespace std;

void sort(vector<int>& arr) {
    int i = 0;
    while (i < arr.size()) {
      
        // If element is not at its correct 
        // position, swap it
        if (arr[arr[i] - 1] != arr[i]) {
            swap(arr[i], arr[arr[i] - 1]);  
          
        } else {
            i++;
        }
    }
}
