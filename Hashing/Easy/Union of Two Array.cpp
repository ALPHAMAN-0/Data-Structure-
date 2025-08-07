/*
Problem:
Given two arrays a[] and b[], return the union of both arrays in any order.

Note:
Union of two arrays is an array having all distinct elements that are present in either array.

Approach:
- Use a Hash Set to keep only unique elements by removing duplicates.
- Create an empty Hash Set and add elements from both arrays.
- The Hash Set ensures no duplicates are stored.
- After adding all elements, create the final union array by iterating through the Hash Set.
*/
#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;
class solve{
    public:
    vector<int> unionOfTwoArray(vector<int> a,vector<int> b){
        unordered_set<int> HashSet;
        for(auto i : a){
            HashSet.insert(i);
        }
        for(auto i : b){
            HashSet.insert(i);
        }
        vector<int> result;
        for(auto i : HashSet){
            result.push_back(i);
        }
        return result;
    }

};
