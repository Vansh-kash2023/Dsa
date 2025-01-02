#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        int n = s.size();
        vector<bool> dp(n + 1, false);
        dp[0] = true; // Base case: an empty string can be segmented

        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (dp[j] && wordSet.count(s.substr(j, i - j))) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[n];
    }
};

int main() {
    Solution solution;
    
    // Test case 1
    string s1 = "leetcode";
    vector<string> wordDict1 = {"leet", "code"};
    cout << (solution.wordBreak(s1, wordDict1) ? "true" : "false") << endl;

    // Test case 2
    string s2 = "applepenapple";
    vector<string> wordDict2 = {"apple", "pen"};
    cout << (solution.wordBreak(s2, wordDict2) ? "true" : "false") << endl;

    // Test case 3
    string s3 = "catsandog";
    vector<string> wordDict3 = {"cats", "dog", "sand", "and", "cat"};
    cout << (solution.wordBreak(s3, wordDict3) ? "true" : "false") << endl;

    return 0;
}
