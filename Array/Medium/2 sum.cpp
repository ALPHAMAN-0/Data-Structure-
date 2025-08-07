/*
Problem:
Given an array arr[] and a target value, the task is
to find all possible indices (i, j) of pairs
(arr[i], arr[j]) whose sum is equal to target and
i != j. We can return pairs in any order, but all
the returned pairs should be internally sorted,
that is for any pair(i, j), i should be less than j.

Approach:
Use a hashmap to store elements and their indices.
For each element, check if (target - current element)
exists in the hashmap. If it does, we have a valid pair.
Ensure that i != j and pairs are internally sorted
(i < j) before adding to the result.
*/
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// function to find all pairs
vector<vector<int>> findAllPairs(vector<int> &arr, int target) {
    int n = arr.size();
    vector<vector<int>> res;

    unordered_map<int, vector<int>> mp;

    for (int i = 0; i < n; i++) {

        // Check if there exists an element that can pair with arr[i]
        if (mp.find(target - arr[i]) != mp.end()) {
          
            // If such an element exists, iterate through its indices
            for (int idx: mp[target - arr[i]]) {
              	res.push_back({idx, i});
            }
        }
      
        // Store the index of the current element in the map
        mp[arr[i]].push_back(i);
    }
    return res;
}
