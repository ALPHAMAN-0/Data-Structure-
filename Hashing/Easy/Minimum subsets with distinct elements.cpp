/*
Problem Statement:
You are given an array of n elements. 
You have to make subsets from the array such that no subset contains duplicate elements. 
Find out the minimum number of subsets possible.

Approach:
To solve this problem, count the frequency of each element in the array. 
The answer will be the maximum frequency among all elements,
because each duplicate of an element must go into a separate subset to avoid duplicates in any subset.
*/
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class minimumSubsets{
    public:
    int minimumSubsetWithDistinctElements(vector<int> arr){
        unordered_map<int,int> elements;
        for(int i=0;i<arr.size();i++){
            elements[arr[i]]++;
        }
        int maxValue = INT_MIN;
        for(auto it : elements){
            maxValue = max(maxValue, it.second);
        }
        return maxValue;
    }
};
