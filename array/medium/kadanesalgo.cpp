#include<bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int maxSum = nums[0];
        for(int i = 0; i<nums.size(); i++){
            if(nums[i]>0){
                sum +=nums[i];
                maxSum = max(maxSum , sum);
                
            }else if(nums[i]<0 && sum>0){
                sum+=nums[i];
                if(sum<0){
                    sum=0;
                }
            }else if(nums[i]<=0 && sum==0){
                maxSum = max(maxSum , nums[i]);
            }
        }
        return maxSum;
    }

int main(){
    vector<int> nums = {-2,-1};
    int res = maxSubArray(nums);
    cout<<res;
    return 0;
}