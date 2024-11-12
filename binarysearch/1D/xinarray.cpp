#include<bits/stdc++.h>
using namespace std;

int search(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2; // Calculate mid to avoid overflow
        
        if (nums[mid] == target) {
            return mid; // Target found at index mid
        }
        else if (nums[mid] < target) {
            left = mid + 1; // Move to the right half
        }
        else {
            right = mid - 1; // Move to the left half
        }
    }
    
    return -1; // Target not found
}

int main(){
    vector<int> nums = {-1,0,3,5,9,12};
    int res = search(nums, 9);
    cout<<res;
    return 0;
}