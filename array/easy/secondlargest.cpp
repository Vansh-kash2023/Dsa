#include <bits/stdc++.h>
using namespace std;

int findSecondLargest(int n, vector<int> &arr)
{
    int largest = arr[0];
    int slargest = INT_MIN;
    for (int i = 1; i < n; i++){
        if (arr[i] > largest){
            slargest = largest;
            largest = arr[i];
        }
        else if (arr[i] < largest && arr[i] > slargest)
        {
            slargest = arr[i];
        }
        if (slargest == INT_MIN)
        {
            slargest = -1;
        }
    }
    return slargest;
}

int main()
{
    vector<int> arr = {2, 2, 2, 2};
    int res = findSecondLargest(4, arr);
    cout << res;
    return 0;
}