#include<bits/stdc++.h>
using namespace std;

void reverseArray(vector<int> &arr , int m) {
    // Write your code here
        // Create a new vector to store the subpart after position m
    vector<int> newv;

    // Copy elements from position m+1 to the end of the original array into newv
    for (int i = m + 1; i < arr.size(); i++) {
        newv.push_back(arr[i]);
    }

    // Reverse the new vector
    reverse(newv.begin(), newv.end());

    // Replace the part of arr after position m with the reversed subpart
    int index = 0;
    for (int i = m + 1; i < arr.size(); i++) {
        arr[i] = newv[index++];
    }
    
    for(auto it: arr){
        cout<<it<<" ";
    }
}

int main(){
    vector<int> vec = {1,2,3,4,4,5,6,7,8,9,10};
    reverseArray(vec, 5);
    return 0;
}