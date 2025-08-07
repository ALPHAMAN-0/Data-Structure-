/*
Problem:
Given two arrays a[] and b[] of size m and n respectively,
determine whether b[] is a subset of a[].
Both arrays are not sorted, and elements are distinct.

Approach:
- Use a hash set to store elements of a[].
- This allows constant time searching.
- Insert all elements of a[] into the hash set.
- For each element in b[], check if it exists in the hash set.
*/
#include<iostream>
#include<unordered_set>
#include<unordered_map>
#include<vector>
using namespace std;

bool isSubset(vector<int> a,vector<int> b){
    unordered_set<int> hashSet(a.begin(), a.end());
    for(int i = 0; i < b.size(); i++) {
        if(hashSet.find(b[i]) == hashSet.end()) {
            return false;
        }
    }
    return true;
}
class Solution {
  public:
    // Function to check if b is a subset of a
    bool isSubset(vector<int> &a, vector<int> &b) {
        // Your code here
        unordered_map<int,int> hashSet;
        for(auto i : a){
            hashSet[i]++;
        }
        for(auto i : b){
            if(hashSet[i]==0)return false;
            hashSet[i]--;
        }
        return true;
    }
};


