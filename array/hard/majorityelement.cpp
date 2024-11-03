#include<bits/stdc++.h>
using namespace std;

vector<int> majorityElement(vector<int>& nums) {
        int req_occ = (nums.size()/3);
        set<int> unique_nums(nums.begin(), nums.end());
        vector<int> res;
        for(auto it:unique_nums){
            int occ=0;
            for(int i = 0; i<nums.size(); i++){
                if(it==nums[i]){
                    occ+=1;
                }
            }
            if(occ>req_occ){
                res.push_back(it);
            }
        }
        return res;
    }

int main(){
    vector<int> nums = {1,2,3,3,5,3,5,5};
    vector<int> res = majorityElement(nums);
    for(auto it:res){
        cout<<it<<" ";
    }
    return 0;
}