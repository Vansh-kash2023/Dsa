#include<bits/stdc++.h>
using namespace std;

int search(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Check if the middle element is the target
        if (nums[mid] == target) {
            return mid;
        }

        // Determine which half is sorted
        if (nums[left] <= nums[mid]) { // Left half is sorted
            if (nums[left] <= target && target < nums[mid]) {
                right = mid - 1; // Target in left half
            } else {
                left = mid + 1;  // Target in right half
            }
        } else { // Right half is sorted
            if (nums[mid] < target && target <= nums[right]) {
                left = mid + 1;  // Target in right half
            } else {
                right = mid - 1; // Target in left half
            }
        }
    }

    // Target not found
    return -1;
}

int main(){
    vector<int> nums = {-1,0,3,5,9,12};
    int res = search(nums, 9);
    cout<<res;
    return 0;
}