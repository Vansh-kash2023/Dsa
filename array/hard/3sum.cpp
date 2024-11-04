#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> result;
    int n = nums.size();
    
    // Step 1: Sort the array
    sort(nums.begin(), nums.end());
    
    // Step 2: Traverse the array
    for (int i = 0; i < n - 2; i++) {
        // Skip duplicate elements for the first element of the triplet
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }
        
        // Step 3: Use two pointers to find the other two numbers
        int left = i + 1;
        int right = n - 1;
        int target = -nums[i];
        
        while (left < right) {
            int sum = nums[left] + nums[right];
            
            if (sum == target) {
                result.push_back({nums[i], nums[left], nums[right]});
                
                // Move left and right pointers and skip duplicates
                while (left < right && nums[left] == nums[left + 1]) {
                    left++;
                }
                while (left < right && nums[right] == nums[right - 1]) {
                    right--;
                }
                
                left++;
                right--;
            } else if (sum < target) {
                left++;
            } else {
                right--;
            }
        }
    }
    
    return result;
}

int main(){
    vector<int> nums = {-1,2,1,0,1,-2};
    vector<vector<int>> res = threeSum(nums);
    for(auto it:res){
        for(auto i : it){
            cout<<i;
        }
        cout<<endl;
    }
    return 0;
}