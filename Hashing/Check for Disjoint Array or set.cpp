/*
Problem: Given two arrays a and b, check if they are disjoint, i.e., there is no element common between both the arrays.

Approach: 
1. Insert all elements of array a into a hash set.
2. For each element of array b, check if it exists in the hash set.
3. If any element from array b is found in the hash set, the arrays are not disjoint; otherwise, they are disjoint.

*/
#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;
class solve{
    public :
    bool isDisjoint(vector<int> a,vector<int> b){
        unordered_set<int> hashSet;
        for(int element : a){
            hashSet.insert(element);
        }
        for(int element : b){
            if(hashSet.find(element) != hashSet.end()){
               return false; 
            }
        }
        return true;
    }
};
