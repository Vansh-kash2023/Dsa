#include <bits/stdc++.h>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        // Mapping of digits to corresponding letters
        vector<string> digitToLetters = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> result;
        string current;

        // Helper function for backtracking
        function<void(int)> backtrack = [&](int index) {
            if (index == digits.size()) {
                result.push_back(current);
                return;
            }

            int digit = digits[index] - '0';
            string letters = digitToLetters[digit];

            for (char letter : letters) {
                current.push_back(letter);
                backtrack(index + 1);
                current.pop_back();
            }
        };

        backtrack(0);
        return result;
    }
};

int main() {
    Solution solution;

    // Test case 1
    string digits1 = "23";
    vector<string> output1 = solution.letterCombinations(digits1);
    cout << "Input: " << digits1 << "\nOutput: [";
    for (size_t i = 0; i < output1.size(); ++i) {
        cout << '"' << output1[i] << '"';
        if (i < output1.size() - 1) cout << ", ";
    }
    cout << "]\n";

    // Test case 2
    string digits2 = "";
    vector<string> output2 = solution.letterCombinations(digits2);
    cout << "Input: " << digits2 << "\nOutput: [";
    for (size_t i = 0; i < output2.size(); ++i) {
        cout << '"' << output2[i] << '"';
        if (i < output2.size() - 1) cout << ", ";
    }
    cout << "]\n";

    // Test case 3
    string digits3 = "2";
    vector<string> output3 = solution.letterCombinations(digits3);
    cout << "Input: " << digits3 << "\nOutput: [";
    for (size_t i = 0; i < output3.size(); ++i) {
        cout << '"' << output3[i] << '"';
        if (i < output3.size() - 1) cout << ", ";
    }
    cout << "]\n";

    return 0;
}
