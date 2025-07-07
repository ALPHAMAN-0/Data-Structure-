/*
Problem:
Given an array of n integers and a target value,
find if there is a pair in the array that sums 
to the target. This is a 2Sum problem variation.

Approach:
Hashing offers an efficient solution. We store each
number in an unordered set while iterating the array.

For each element, we:
1. Calculate its complement (target - current number)
2. Check if complement exists in our set
    - If yes: pair found
    - If no: add current number to set

This approach reduces time complexity to O(n).

Algorithm steps:
- Create empty unordered set
- Iterate through array:
  - Find complement (target - current number)
  - Check if complement in set
  - If found, return true
  - Otherwise, add current number to set
- Return false if no pair found
*/
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// Function to check whether any pair exists
// whose sum is equal to the given target value
bool twoSum(vector<int> &arr, int target){
  
    // Create an unordered_set to store the elements
    unordered_set<int> s;

    // Iterate through each element in the vector
    for (int i = 0; i < arr.size(); i++){

        // Calculate the complement that added to
        // arr[i], equals the target
        int complement = target - arr[i];

        // Check if the complement exists in the set
        if (s.find(complement) != s.end())
            return true;

        // Add the current element to the set
        s.insert(arr[i]);
    }
  
    // If no pair is found
    return false;
}
