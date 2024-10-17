#include<bits/stdc++.h>
using namespace std;

vector<int> rotateArray(vector<int>arr, int k) {
    // Write your code here.
    for(int i=0; i<k; i++){
        int temp=arr[0];
        for(int i=0;i<arr.size();i++)
            {
                arr[i]=arr[i+1];
            }
        arr[arr.size()-1]=temp;
        }
    return arr;
}

int main(){
    vector<int>arr = {1,2,3,4,5};
    vector<int> res = rotateArray(arr, 5);
    for(auto it: res){
        cout<<it<<" ";
    }
    return 0;
}