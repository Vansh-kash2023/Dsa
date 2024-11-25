#include<bits/stdc++.h>
using namespace std;

int findKthPositive(vector<int>& arr, int k) {
        int missingCount = 0; // Count of missing integers
        int current = 1;     // Start checking from 1
        int index = 0;       // Index for traversing the array

        // Loop until we find the kth missing number
        while (true) {
            // If current is not in arr, it's missing
            if (index >= arr.size() || arr[index] != current) {
                missingCount++;
                // If we found the kth missing number, return it
                if (missingCount == k) {
                    return current;
                }
            } else {
                // Move to the next element in arr
                index++;
            }
            // Increment the current number to check
            current++;
        }
}

int main(){
    vector<int> nums = {2,3,4,7,11};
    int k = 5;
    int res = findKthPositive(nums, k);
    cout<<res;
    return 0;
}