/**
 * Problem Statement:
 * Given an array arr[] of size n, where each element is a number from 1 to n-1 (inclusive) in random order,
 * and exactly one element is repeated. The task is to find the repetitive element.
 *
 * Approach:
 * - Use an unordered_set to keep track of elements that have been seen so far.
 * - Iterate through the array:
 *   - If the current element is already present in the set, it is the repeating element; return it.
 *   - Otherwise, insert the element into the set.
 * - If no repeating element is found (should not happen as per problem constraints), return -1.
 */
#include<iostream>
#include<unordered_set>
using namespace std;

class OnlyRepeating {
public:
    int findRepeating(int arr[], int n) {
        unordered_set<int> seen;
        for (int i = 0; i < n; i++) {
            if (seen.find(arr[i]) != seen.end()) {
                return arr[i];
            }
            seen.insert(arr[i]);
        }
        return -1;  
    }
};
