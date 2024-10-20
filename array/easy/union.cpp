#include <bits/stdc++.h>
using namespace std;

vector<int> findUnion(vector<int> &a, vector<int> &b)
{
    set<int> unionSet(a.begin(), a.end());
    unionSet.insert(b.begin(), b.end()); 

    vector<int> res(unionSet.begin(), unionSet.end());
    return res;
}

int main()
{
    vector<int> a = {1, 2, 3, 3, 4, 5};
    vector<int> b = {1, 2, 3, 3, 4, 5, 7, 8, 8, 9};
    vector<int> res = findUnion(a, b);
    for (auto it : res)
    {
        cout << it << " ";
    }
    return 0;
}