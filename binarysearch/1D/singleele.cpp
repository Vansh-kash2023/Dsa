#include<bits/stdc++.h>
using namespace std;

int singleNonDuplicate(vector<int>& nums) {
    int low = 0, high = nums.size() - 1;

    while (low < high) {
        int mid = low + (high - low) / 2;

        // Check if mid is part of a pair
        bool isEvenIndex = (mid % 2 == 0);
        if ((isEvenIndex && nums[mid] == nums[mid + 1]) ||
            (!isEvenIndex && nums[mid] == nums[mid - 1])) {
            // Single element is in the right half
            low = mid + 1;
        } else {
            // Single element is in the left half
            high = mid;
        }
    }

    // The single element is at index 'low'
    return nums[low];
}

int main(){
    vector<int> nums = {1,1,2,3,3,4,4,8,8};
    int res = singleNonDuplicate(nums);
    cout<<res;
    return 0;
}