#include<bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;  // To store the number and its index

        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];

        // Check if the complement is already in the map
            if (mp.find(complement) != mp.end()) {
                return {mp[complement], i};  // Return the indices
            }

        // Store the number with its index in the map
            mp[nums[i]] = i;
        }

        return {};  // Return an empty vector if no solution is found
    }

int main(){
    vector<int> nums = {2,7,11,15};
    vector<int> res = twoSum(nums, 9);
    for(auto it:res){
        cout<<it<<" ";
    }
    return 0;
}