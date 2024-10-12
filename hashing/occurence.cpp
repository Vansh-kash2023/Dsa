#include <bits/stdc++.h>
using namespace std;

void frequencyCount(vector<int> &arr, int N, int P)
{
    // do modify in the given array
    vector<int> occ;
    for (int i = 1; i <= N; i++)
    {
        int count = 0;
        for (auto it : arr)
        {
            if (i == it)
            {
                count += 1;
            }
        }
        occ.push_back(count);
    }
    for (auto it : occ)
    {
        cout << it << " ";
    }
}

int main()
{
    vector<int> arr = {2, 3, 2, 3, 5};
    frequencyCount(arr, 5, 5);
    return 0;
}