/*
Problem:
Given an integer array arr[], find the element that appears most frequently.
If multiple elements have the same highest frequency, return the largest among them.

Approach:
- Use a hash table to count the frequency of each element efficiently.
- After building the frequency map, identify the element with the highest frequency.
- If there is a tie, choose the largest element.
*/

#include<iostream>
#include<unordered_map>
#include<map>
#include<vector>
using namespace std;
class Solution {
  public:
  int mostFreqEle(vector<int>& arr) {
    int n = arr.size();
    
    // Insert all elements in hash map.
    unordered_map<int, int> freq;
    for (int i = 0; i < n; i++)
        freq[arr[i]]++;

    // find the max frequency
    int maxCnt = 0, res = -1;
    for (auto i : freq) {
        int val = i.first, cnt = i.second;
        
        // Update if frequency is higher or same but value is larger
        if (maxCnt < cnt || (cnt == maxCnt && val > res)) {
            res = val;
            maxCnt = cnt;
        }
    }

    return res;
}
};
