#include<bits/stdc++.h>
using namespace std;

void moveZeroes(vector<int>& nums) {
    int n = nums.size();
    int nonZeroIndex = 0; // Points to the index where the next non-zero element should go.

    // Move all non-zero elements to the beginning of the array.
    for (int i = 0; i < n; i++) {
        if (nums[i] != 0) {
            nums[nonZeroIndex] = nums[i];
            nonZeroIndex++;
        }
    }

    // Fill the rest of the array with zeros.
    for (int i = nonZeroIndex; i < n; i++) {
        nums[i] = 0;
    }
}

int main(){
    vector<int> nums = {2,0,6,4,0,0,6,3,2};
    moveZeroes(nums);
    return 0;
}