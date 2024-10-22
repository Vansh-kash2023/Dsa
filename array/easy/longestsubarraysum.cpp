#include<bits/stdc++.h>
using namespace std;

int getLongestSubarray(vector<int>& nums, int k){
    // Write your code here
    int maxLength = 0;

    for (int i = 0; i < nums.size(); i++) {
        int sum = 0;
        for (int j = i; j < nums.size(); j++) {
            sum += nums[j];
            if (sum == k) {
                maxLength = max(maxLength, j - i + 1);  // Update the max length
            }
        }
    }

    return maxLength;
}

int main(){
    vector<int> nums = {1,2,2,0,4,1,2,3,5};
    int res = getLongestSubarray(nums, 5);
    cout<<res;
    return 0;
}