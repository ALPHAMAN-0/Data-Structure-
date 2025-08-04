
// Problem: Given an array arr[] of n integers and a target value,
// find the number of pairs of integers in the array whose sum is equal to target.

// Approach 1 (Hash Map - Implemented Below):
// - Traverse the array and for each element, check if the complement (target - arr[i]) exists in a hash map.
// - If it exists, increment the count by the frequency of the complement.
// - Add the current element to the hash map.
// - Time Complexity: O(n), Space Complexity: O(n).

// Approach 2 (Two Pointer Technique - Not Implemented Here):
// - Sort the array.
// - Use two pointers: one at the start (left) and one at the end (right).
// - If arr[left] + arr[right] < target, move left pointer to the right to increase the sum.
// - If arr[left] + arr[right] > target, move right pointer to the left to decrease the sum.
// - If arr[left] + arr[right] == target, count the pairs (considering duplicates) and update the result.
// - Time Complexity: O(n log n) due to sorting, Space Complexity: O(1).

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    int countPair(vector<int> arr, int target)
    {
        unordered_map<int, int> freq;
        int cnt = 0;

        for (int i = 0; i < arr.size(); i++)
        {
            int complement = target - arr[i];
            if (freq.find(complement) != freq.end())
            {
                cnt += freq[complement];
            }
            freq[arr[i]]++;
        }
        return cnt;
    }
};
