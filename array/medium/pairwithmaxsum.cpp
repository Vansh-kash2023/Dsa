#include <bits/stdc++.h>
using namespace std;

int pairWithMaxSum(vector<int> &arr)
{
    // Your code goes here
    int maxSum = 0;
    if (arr.size() < 2) return 0;

    for (int i = 0; i < arr.size() - 1; i++) {
        int sum = arr[i] + arr[i + 1];
        maxSum = max(maxSum, sum);
    }
    
    return maxSum;
}

int main()
{
    vector<int> arr = {4, 3, 1, 5, 6};
    int res = pairWithMaxSum(arr);
    cout << res;
    return 0;
}