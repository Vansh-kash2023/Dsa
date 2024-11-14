#include<bits/stdc++.h>
using namespace std;

vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> result = {-1, -1};
    
    // Function to find the leftmost index of the target
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    // Check if the target exists in the array
    if (left >= nums.size() || nums[left] != target) {
        return result; // Target not found
    }
    
    // Set the starting position
    result[0] = left;
    
    // Reset right for finding the rightmost index
    right = nums.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] > target) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    
    // Set the ending position
    result[1] = right;
    
    return result;
}

int main(){
    vector<int> nums = {2,2,4,5,7,3,1,5,3,5};
    int target = 5;
    vector<int> result = searchRange(nums, target);
    for(auto it:result){
        cout<<it<<" ";
    }
    return 0;
}