#include<bits/stdc++.h>
using namespace std;

int largestElement(vector<int> &arr, int n) {
    // Write your code here.
    int largest = 0;
    for(auto it:arr){
        if(it>largest){
            largest = it;
        }
    }
    return largest;
}

int main(){
    vector<int> arr = {1,2,3,4,5,80};
    int a = largestElement(arr, 5);
    cout<<a;
    return 0;
}