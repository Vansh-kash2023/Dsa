#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> subset;
        sort(nums.begin(), nums.end()); // Sort to handle duplicates
        backtrack(nums, 0, subset, result);
        return result;
    }

private:
    void backtrack(vector<int>& nums, int start, vector<int>& subset, vector<vector<int>>& result) {
        result.push_back(subset); // Add the current subset

        for (int i = start; i < nums.size(); ++i) {
            // Skip duplicates
            if (i > start && nums[i] == nums[i - 1]) continue;

            subset.push_back(nums[i]);
            backtrack(nums, i + 1, subset, result);
            subset.pop_back(); // Backtrack
        }
    }
};

int main() {
    Solution solution;
    
    vector<int> nums1 = {1, 2, 2};
    vector<vector<int>> result1 = solution.subsetsWithDup(nums1);

    cout << "Subsets for [1, 2, 2]:\n";
    for (const auto& subset : result1) {
        cout << "[";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "]\n";
    }

    vector<int> nums2 = {0};
    vector<vector<int>> result2 = solution.subsetsWithDup(nums2);

    cout << "\nSubsets for [0]:\n";
    for (const auto& subset : result2) {
        cout << "[";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "]\n";
    }

    return 0;
}
