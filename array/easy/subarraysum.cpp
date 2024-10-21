#include<bits/stdc++.h>
using namespace std;

int subarraySum(vector<int>& nums, int k) {
    int subarray = 0;
    for(int i = 0; i<nums.size(); i++){
    int sum = 0;
        for(int j=i; j<nums.size(); j++){
            sum = sum+ nums[j];
            if(sum==k){
                subarray+=1;
            }
        }
    }
    return subarray;
}

int main(){
    vector<int> input = {1,2,2,4,4,5,6,1,2,4,5,9};
    int res = subarraySum(input, 9);
    cout<<res;
    return 0;
}