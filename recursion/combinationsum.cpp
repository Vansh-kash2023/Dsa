#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void backtrack(vector<int>& candidates, int target, vector<int>& current, vector<vector<int>>& result, int start) {
        if (target == 0) {
            result.push_back(current);
            return;
        }

        for (int i = start; i < candidates.size(); i++) {
            if (candidates[i] > target) continue; // Skip if the candidate is larger than the remaining target
            
            current.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], current, result, i);
            current.pop_back(); // Backtrack
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        backtrack(candidates, target, current, result, 0);
        return result;
    }
};

int main() {
    Solution solution;
    vector<int> candidates;
    int target;

    // Example input
    candidates = {2, 3, 6, 7};
    target = 7;

    vector<vector<int>> result = solution.combinationSum(candidates, target);

    // Output the results
    cout << "Combinations that sum to " << target << ":" << endl;
    for (const auto& combination : result) {
        cout << "[";
        for (int i = 0; i < combination.size(); i++) {
            cout << combination[i];
            if (i < combination.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
    }

    return 0;
}
