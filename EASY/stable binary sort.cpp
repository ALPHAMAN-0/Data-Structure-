/*
Problem:
-------
Partition array by even/odd elements.
Keep stable ordering (preserve relative
order within even & odd groups).

For binary arrays (0s and 1s), this
equals sorting.

Approach:
--------
Naive Partitioning:
1. Create temp array
2. Add all even elements (in order)
3. Add all odd elements (in order)
4. Copy back to original array
*/
#include <iostream>
#include <vector>
using namespace std;

// Function for stable partitioning of even-odd(binary) array 
void partition(vector<int> &arr) {
  	int n = arr.size();
  
  	// create a temporary array to store the elements
  	vector<int> temp(n);
  	int idx = 0;
  	
  	// First fill even elements into the temporary array
  	for (int i = 0; i < n; i++) {
      	if (arr[i] % 2 == 0) 
          	temp[idx++] = arr[i];
    }
  	
  	// Now fill odd elements into the temporary array
  	for (int i = 0; i < n; i++) {
      	if (arr[i] & 1) 
          	temp[idx++] = arr[i];
    }
  	
  	// copy the elements from temp to arr
  	arr = temp;
}
