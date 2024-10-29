#include<bits/stdc++.h>
using namespace std;

vector<int> leaders(vector<int>& arr) {
    int n = arr.size();
    vector<int> result;
    int maxFromRight = arr[n - 1];

    result.push_back(maxFromRight);

    for (int i = n - 2; i >= 0; i--) {
        if (arr[i] >= maxFromRight) {
            maxFromRight = arr[i];
            result.push_back(arr[i]);
        }
    }

    reverse(result.begin(), result.end());
    return result;
}

int main(){
    vector<int> arr = {12,45,2,4,6,23,12,1};
    vector<int> res = leaders(arr);
    for(auto it:res){
        cout<<it<<" ";
    }
    return 0;
}