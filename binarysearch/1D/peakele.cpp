#include<bits/stdc++.h>
using namespace std;

int findPeakElement(vector<int>& nums) {
    int left = 0, right = nums.size() - 1;
    
    while (left < right) {
        int mid = left + (right - left) / 2;
        
        if (nums[mid] > nums[mid + 1]) {
            // Peak is on the left side (including mid)
            right = mid;
        } else {
            // Peak is on the right side
            left = mid + 1;
        }
    }
    
    // Left and right converge to the peak index
    return left;
}

int main(){
    vector<int> nums = {1,8,1,5,3};
    int res = findPeakElement(nums);
    cout<<res;
    return 0;
}