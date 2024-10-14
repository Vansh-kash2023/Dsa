#include<bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int> &arr, int n) {
	// Write your code here.
    vector<int> unique;
    int prev = 0;
    for(auto it:arr){
        if(it!=prev){
            unique.push_back(it);
            prev=it;
        }
    }
    int length = unique.size();
    return length;
}

int main(){
    vector<int> arr = {1,1,2,3,3,3,4,5,5,5};
    int res = removeDuplicates(arr, 10);
    cout<<res;
    return 0;
}