#include<bits/stdc++.h>
using namespace std;

int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;

    sort(nums.begin(), nums.end());
    int longest = 1, count = 1;

    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] == nums[i - 1] + 1) { // Check if consecutive
            count++;
        } else if (nums[i] != nums[i - 1]) { // Check if not a duplicate
            longest = max(longest, count);
            count = 1;
        }
    }
    return max(longest, count);
    }

int main(){
    vector <int> nums = {0,3,7,2,5,8,4,6,0,1};
    int res = longestConsecutive(nums);
    cout<<res;
    return 0;
}