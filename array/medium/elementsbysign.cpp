#include<bits/stdc++.h>
using namespace std;

vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> res;
        for(int i=0; i<nums.size(); i++){
            if(i==0 || i%2==0){
                if(nums[i]<0){
                    for(int j=i+1; j<nums.size(); j++){
                        if(nums[j]>0){
                            int temp = nums[i];
                            nums[i] = nums[j];
                            nums[j] = temp;
                            break;
                        }
                    }
                }
            }else if(i==1 || i%3==0){
                if(nums[i]>0){
                    for(int j=i+1; j<nums.size(); j++){
                        if(nums[j]<0){
                            int temp = nums[i];
                            nums[i] = nums[j];
                            nums[j] = temp;
                            break;
                        }
                    }
                }
            }
        }
        res = nums;
        return res;
    }

int main(){
    vector<int> nums = {1,2,-5,3,-2,-1,-5};
    vector<int> res = rearrangeArray(nums);
    for(auto it: res){
        cout<<it<<" ";
    }
    return 0;
}