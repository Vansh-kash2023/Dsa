#include<bits/stdc++.h>
using namespace std;

int numberOfPermutations(int n, vector<vector<int>>& requirements) {
        vector<vector<int>> dp(n + 1, vector<int>(401, 0));
        vector<int> req(n + 1, -1);

        for (auto& r : requirements) {
            req[r[0] + 1] = r[1];
        }

        const int mod = 1e9 + 7;

        if (req[1] <= 0) {
            dp[1][0] = 1;
        }

        for (int i = 2; i <= n; i++) {
            for (int c = 0; c < i; c++) {
                for (int j = 0; j + c <= 400; j++) {
                    if (req[i] != -1 && j + c != req[i]) {
                        continue;
                    }
                    dp[i][j + c] += dp[i - 1][j];
                    dp[i][j + c] %= mod;
                }
            }
        }

        return dp[n][req[n]];
    }

int main(){
    int n = 3;
    vector<vector<int>> requirements = {{2,2}, {0,0}};
    int res = numberOfPermutations(n, requirements);
    cout<<res;
    return 0;
}