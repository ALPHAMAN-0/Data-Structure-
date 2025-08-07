/*
PROBLEM:
Given an array of size n containing integers from 1 to n, find:
1. One missing number (from the range 1 to n)
2. One repeating number (that appears twice)

APPROACH 1 (Mathematical):
- Calculate expected sum of numbers 1 to n: n*(n+1)/2
- Calculate expected sum of squares: n*(n+1)*(2n+1)/6
- Find actual sum and sum of squares of array elements
- Let x = missing number, y = repeating number
- From the differences, we get:
    - expected_sum - actual_sum = x - y
    - expected_sum_squares - actual_sum_squares = x² - y²
- Solve these equations to find x and y

APPROACH 2 (XOR):
- XOR all array elements with numbers 1 to n
- This gives XOR of missing and repeating numbers
- Find a set bit in this result
- Divide all numbers into two groups based on this bit
- XOR each group separately to identify both numbers
*/
vector<int> findTwoElementApproach1(vector<int> &arr)
{
    int n = arr.size();

    int s = (n * (n + 1)) / 2;
    int ssq = (n * (n + 1) * (2 * n + 1)) / 6;

    int missing = 0, repeating = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        s -= arr[i];
        ssq -= arr[i] * arr[i];
    }

    missing = (s + ssq / s) / 2;
    repeating = missing - s;

    return {repeating, missing};
}
vector<int> findTwoElementApproach2(vector<int> &arr)
{
    int n = arr.size();
    int xorVal = 0;

    // Get the xor of all array elements
    // And numbers from 1 to n
    for (int i = 0; i < n; i++)
    {
        xorVal ^= arr[i];
        xorVal ^= (i + 1); // 1 to n numbers
    }

    // Get the rightmost set bit in xorVal
    int setBitIndex = xorVal & ~(xorVal - 1);

    int x = 0, y = 0;

    // Now divide elements into two sets
    // by comparing rightmost set bit
    for (int i = 0; i < n; i++)
    {

        // Decide whether arr[i] is in first set
        // or second
        if (arr[i] & setBitIndex)
        {
            x ^= arr[i];
        }
        else
        {
            y ^= arr[i];
        }

        // Decide whether (i+1) is in first set
        // or second
        if ((i + 1) & setBitIndex)
        {
            x ^= (i + 1);
        }
        else
        {
            y ^= (i + 1);
        }
    }

    // x and y are the repeating and missing values.
    // to know which one is what, traverse the array
    int missing, repeating;

    int xCnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == x)
        {
            xCnt++;
        }
    }

    if (xCnt == 0)
    {
        missing = x;
        repeating = y;
    }
    else
    {
        missing = y;
        repeating = x;
    }

    return {repeating, missing};
}
