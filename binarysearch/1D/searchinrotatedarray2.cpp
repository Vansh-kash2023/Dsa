#include<bits/stdc++.h>
using namespace std;

bool search(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Check if the middle element is the target
        if (nums[mid] == target) {
            return true;
        }

        // Handle duplicates by skipping them
        if (nums[left] == nums[mid] && nums[mid] == nums[right]) {
            left++;
            right--;
        }
        // Left side is sorted
        else if (nums[left] <= nums[mid]) {
            if (nums[left] <= target && target < nums[mid]) {
                right = mid - 1; // Target is in the left sorted part
            } else {
                left = mid + 1; // Target is in the right part
            }
        }
        // Right side is sorted
        else {
            if (nums[mid] < target && target <= nums[right]) {
                left = mid + 1; // Target is in the right sorted part
            } else {
                right = mid - 1; // Target is in the left part
            }
        }
    }

    return false; // Target not found
}

int main(){
    vector<int> nums = {2,5,6,0,0,1,2};
    bool res = search(nums, 0);
    cout<<res;
    return 0;
}