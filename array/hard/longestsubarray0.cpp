#include <bits/stdc++.h>
using namespace std;

int LongestSubsetWithZeroSum(vector<int> arr) {
    unordered_map<int, int> sumMap;  // Map to store cumulative sum and its first occurrence index
    int max_length = 0;
    int cumulative_sum = 0;

    for (int i = 0; i < arr.size(); i++) {
        cumulative_sum += arr[i];

        // If cumulative_sum is 0, we found a subarray from start to i with zero sum
        if (cumulative_sum == 0) {
            max_length = i + 1;
        }

        // If cumulative_sum has been seen before, update max_length
        if (sumMap.find(cumulative_sum) != sumMap.end()) {
            max_length = max(max_length, i - sumMap[cumulative_sum]);
        } else {
            // Store the first occurrence of this cumulative_sum
            sumMap[cumulative_sum] = i;
        }
    }

    return max_length;
}

int main() {
    vector<int> arr = {1, 3, -1, 4, -4};
    int res = LongestSubsetWithZeroSum(arr);
    cout << res;
    return 0;
}
