
// Approach 1: Sorting + Binary Search
// 1. Sort the array in non-decreasing order.
// 2. For each element arr[i] (from 0 to n-2):
//    a. Compute complement = target - arr[i].
//    b. Perform binary search for complement in subarray arr[i+1...n-1].
//    c. If found, return true (pair exists).
// 3. If no such pair is found after the loop, return false.

// Approach 2: Two-Pointer Technique (for sorted arrays)
// 1. Sort the array if not already sorted.
// 2. Initialize two pointers: left at 0, right at n-1.
// 3. While left < right:
//    a. Calculate sum = arr[left] + arr[right].
//    b. If sum == target, return true (pair exists).
//    c. If sum < target, increment left pointer (left++).
//    d. If sum > target, decrement right pointer (right--).
// 4. If no such pair is found, return false.

// Approach 3: Hashing (Unordered Set)
// 1. Create an empty unordered set.
// 2. Iterate through each element in the array:
//    a. Compute complement = target - current element.
//    b. If complement exists in the set, return true (pair exists).
//    c. Otherwise, insert current element into the set.
// 3. If no such pair is found after the loop, return false.

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class sumPair{
    public:
    bool isFound(vector<int> arr, int target){
        unordered_set<int> hashSet;
        for(int i=0;i<arr.size();i++){
            int value = target - arr[i];
            if(hashSet.find(value) != hashSet.end()){
                return true;
            }
            hashSet.insert(arr[i]);
        }
        return false;
    }
};
