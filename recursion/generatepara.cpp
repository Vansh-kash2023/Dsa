#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string current;
        backtrack(result, current, 0, 0, n);
        return result;
    }

private:
    void backtrack(vector<string>& result, string& current, int open, int close, int max) {
        if (current.size() == max * 2) {
            result.push_back(current);
            return;
        }

        if (open < max) {
            current.push_back('(');
            backtrack(result, current, open + 1, close, max);
            current.pop_back(); // Undo the last choice (backtrack)
        }

        if (close < open) {
            current.push_back(')');
            backtrack(result, current, open, close + 1, max);
            current.pop_back(); // Undo the last choice (backtrack)
        }
    }
};

int main() {
    Solution solution;

    // Input value for n
    int n;
    cout << "Enter the number of pairs of parentheses: ";
    cin >> n;

    // Generate parentheses
    vector<string> result = solution.generateParenthesis(n);

    // Print the results
    cout << "Generated Parentheses Combinations:" << endl;
    for (const string& combination : result) {
        cout << combination << endl;
    }

    return 0;
}
