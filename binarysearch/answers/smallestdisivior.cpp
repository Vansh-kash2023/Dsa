#include<bits/stdc++.h>
using namespace std;

int smallestDivisor(vector<int>& nums, int threshold) {
    int left = 1, right = *max_element(nums.begin(), nums.end());
    int result = right;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Calculate the sum of divisions
        int sum = 0;
        for (int num : nums) {
            sum += (num + mid - 1) / mid; // Equivalent to ceil(num / mid)
        }

        if (sum <= threshold) {
            result = mid; // Record the possible answer
            right = mid - 1; // Try smaller divisors
        } else {
            left = mid + 1; // Try larger divisors
        }
    }

    return result;
}

int main(){
    vector<int> nums = {1,2,5,9};
    int limit = 6;
    int res = smallestDivisor(nums, limit);
    cout<<res;
    return 0;
}