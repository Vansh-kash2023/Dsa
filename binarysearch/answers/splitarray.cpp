#include<bits/stdc++.h>
using namespace std;

int splitArray(vector<int>& nums, int k) {
        // Helper function to check if a max subarray sum of 'maxSum' is feasible
        auto canSplit = [&](int maxSum) {
            int subarrayCount = 1, currentSum = 0;
            for (int num : nums) {
                if (currentSum + num > maxSum) {
                    subarrayCount++;
                    currentSum = num;
                    if (subarrayCount > k) return false;
                } else {
                    currentSum += num;
                }
            }
            return true;
        };
        
        // Binary search for the minimum largest sum
        int left = *max_element(nums.begin(), nums.end()), right = accumulate(nums.begin(), nums.end(), 0);
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (canSplit(mid)) {
                right = mid;  // Try for a smaller max sum
            } else {
                left = mid + 1;  // Increase the max sum
            }
        }
        
        return left;
    }

int main(){
    vector<int> nums = {7,2,5,10,18};
    int k=2;
    int res = splitArray(nums, k);
    cout<<res;
    return 0;
}