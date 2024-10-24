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
    unordered_map<int, int> occ;
    int majority = -1;
    
    for (int i = 0; i < n; i++) {
        occ[arr[i]]++;
        
        if (occ[arr[i]] > n / 2) {
            majority = arr[i];
            break;
        }
    }

    return majority;
}

int main(){
    int arr[8] = {1,2,5,5,5,5};
    int res = findMajorityElement(arr, 6);
    cout<<res;
    return 0;
}