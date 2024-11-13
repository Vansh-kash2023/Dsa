#include<bits/stdc++.h>
using namespace std;


int searchInsert(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;  // Find the middle index
        
        if (nums[mid] == target) {
            return mid;  // Target found, return the index
        } else if (nums[mid] < target) {
            left = mid + 1;  // Search in the right half
        } else {
            right = mid - 1;  // Search in the left half
        }
    }
    
    // If not found, 'left' is the insertion point
    return left;
}

int main(){
    vector<int> nums = {-1,0,3,5,9,12};
    int res = searchInsert(nums, 9);
    cout<<res;
    return 0;
}