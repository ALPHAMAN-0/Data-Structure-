/*
The problem asks us to rearrange an array so that:
- Elements at **even indices** (0, 2, 4...) are **greater than** their adjacent elements
- Elements at **odd indices** (1, 3, 5...) are **smaller than** their adjacent elements

This creates a zigzag pattern: `A[0] > A[1] < A[2] > A[3] < A[4] > ...`

## Algorithm

1. **Sort** the array in ascending order
2. Split the array into two halves:
   - **Larger half**: Elements from the middle to end
   - **Smaller half**: Elements from start to middle
3. Fill the array in this pattern:
   - **Even positions** (0, 2, 4...): Elements from larger half
   - **Odd positions** (1, 3, 5...): Elements from smaller half

## Example

Original array: [1, 2, 3, 4, 5, 6]
Sorted array:   [1, 2, 3, 4, 5, 6]

Smaller half: [1, 2, 3]
Larger half:  [4, 5, 6]

Rearranged array: [4, 1, 5, 2, 6, 3]

The time complexity is O(n log n) due to sorting.
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> rearrangeArray(vector<int> &arr) {

    int n = arr.size();

    sort(arr.begin(), arr.end());

    vector<int> ans(n);
    int ptr1 = 0, ptr2 = n - 1;
    for (int i = 0; i < n; i++) {

        // Assign even indexes with maximum elements
        if ((i + 1) % 2 == 0)
            ans[i] = arr[ptr2--];

        // Assign odd indexes with remaining elements
        else
            ans[i] = arr[ptr1++];
    }

    return ans;
}

int main() {
    vector<int> arr = {1, 2, 2, 1};

    vector<int> res = rearrangeArray(arr);
    for (auto it : res)
        cout << it << " ";
    return 0;
}
