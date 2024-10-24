#include<bits/stdc++.h>
using namespace std;

// Leetcode
// int majorityElement(vector<int>& nums) {
//         set<int> uniqueset(nums.begin(), nums.end());
//         unordered_map<int,int> occ;
//         int majorityelement = 0;
//         for(auto it:uniqueset){
//         int count = 0;
//             for(int i = 0; i<nums.size(); i++){
//                 if(it==nums[i]){
//                     count+=1;
//                 }
//             }
//             occ.insert(make_pair(it,count));
//         }
//         int largest=0;
//         for(auto it:occ){
//             if(it.second>largest){
//                 largest = it.second;
//                 majorityelement = it.first;
//             }
//         }
//         return majorityelement;
//     }


// Code360
int findMajorityElement(int arr[], int n) {
	// Write your code here.
    set<int> unique;
    for(int i =0; i<n; i++){
        unique.insert(arr[i]);
    }
    int majority=-2;
    unordered_map<int,int> occ;
    for(auto it:unique){
        int count = 0;
        for(int i = 0; i<n; i++){
            if(it==arr[i]){
                count+=1;
            }
        }
        if(count>n/2){
            occ.insert(make_pair(it,count));
        }
    }
    int largest = 0;
    for(auto it:occ){
        if(it.second>largest){
            largest = it.second;
            majority = it.first;
        }
    }

    if(majority==-2){
        return -1;
    }else{
        return majority;
    }
}

int main(){
    int arr[8] = {1,2,5,5,5,4};
    int res = findMajorityElement(arr, 8);
    cout<<res;
    return 0;
}