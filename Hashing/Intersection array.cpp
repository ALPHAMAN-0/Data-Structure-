/*
Problem:
Given two arrays a[] and b[], find their intersection —
the unique elements that appear in both.
Ignore duplicates, and the result can be in any order.

Approach:
Use hashing.
*/

#include<iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution {
  public:
    vector<int> intersect(vector<int>& a, vector<int>& b) {
        // code here
        vector<int> result;
        unordered_set<int> setA(a.begin(),a.end());
        for(auto i:b){
            if(setA.find(i)!=setA.end()){
                result.push_back(i);
                setA.erase(i);
            }
        }
        return result;
    }
};
