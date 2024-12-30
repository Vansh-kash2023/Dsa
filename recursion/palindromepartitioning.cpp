#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> currentPartition;
        backtrack(0, s, currentPartition, result);
        return result;
    }

private:
    void backtrack(int start, const string &s, vector<string> &currentPartition, vector<vector<string>> &result) {
        if (start == s.size()) {
            result.push_back(currentPartition);
            return;
        }
        
        for (int end = start; end < s.size(); ++end) {
            if (isPalindrome(s, start, end)) {
                currentPartition.push_back(s.substr(start, end - start + 1));
                backtrack(end + 1, s, currentPartition, result);
                currentPartition.pop_back();
            }
        }
    }

    bool isPalindrome(const string &s, int start, int end) {
        while (start < end) {
            if (s[start] != s[end]) return false;
            ++start;
            --end;
        }
        return true;
    }
};

int main() {
    Solution solution;
    string input1 = "aab";
    string input2 = "a";

    vector<vector<string>> result1 = solution.partition(input1);
    vector<vector<string>> result2 = solution.partition(input2);

    cout << "Partitions for input \"" << input1 << "\":" << endl;
    for (const auto &partition : result1) {
        cout << "[";
        for (const auto &p : partition) {
            cout << "\"" << p << "\" ";
        }
        cout << "]" << endl;
    }

    cout << "\nPartitions for input \"" << input2 << "\":" << endl;
    for (const auto &partition : result2) {
        cout << "[";
        for (const auto &p : partition) {
            cout << "\"" << p << "\" ";
        }
        cout << "]" << endl;
    }

    return 0;
}
