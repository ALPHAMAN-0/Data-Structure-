/*
Problem: Minimum Cost to Reduce Array Size to 1

Given an array of integers, reduce it to a single element by repeatedly:
1. Select any pair of elements
2. Remove the larger of the two elements
3. Pay a cost equal to the value of the smaller element

Each operation reduces the array size by 1.
Find the minimum total cost to reduce the array to a single element.

Example:
For array [4, 3, 2]:
- Remove 4 and keep 3, cost = 3
- Remove 3 and keep 2, cost = 2
- Total cost = 5

The algorithm actually finds a more efficient solution: (n-1) * min_element
*/
#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

// function to calculate the minimum cost
int cost(vector<int>& a)
{
    // Minimum cost is (size - 1) multiplied with minimum element.
    int n = a.size();
    return (n - 1) * (*min_element(a.begin(), a.end()));
}

int main()
{
    vector<int> a = { 4, 3, 2 };
    cout << cost(a) << endl;
    return 0;
}
