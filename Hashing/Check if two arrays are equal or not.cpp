/*
Problem:
Given two arrays, a and b of equal length. 
Determine if the arrays are equal:
- Both contain the same elements.
- Order does not matter.
- Counts of repeated elements must match.

Approach:
Use a hash map to count elements in one array,
then verify counts against the second array.
*/
#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class solve{
    public:
    bool isEqual(vector<int> a,vector<int> b){
    unordered_map<int,int> hashSet;
    
    if(a.size() != b.size()){
        return false;
    }

    for(auto i : a){
        hashSet[i]++;
    }

    for(auto i : b){
        if(hashSet.find(i) == hashSet.end() || hashSet[i] == 0){
            return false;
        }
        hashSet[i]--;
    
    }
        return true;
    }
};
