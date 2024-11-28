#include<bits/stdc++.h>
using namespace std;

int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size();
        int maxTime = n + 1; // Maximum time we need to consider (all walls painted one by one).

        // Initialize dp array with a large value.
        vector<int> dp(maxTime, INT_MAX);
        dp[0] = 0;

        for (int i = 0; i < n; ++i) {
            vector<int> newDp = dp; // Create a copy to update values.

            for (int t = 0; t < maxTime; ++t) {
                if (dp[t] != INT_MAX) {
                    // Update dp for painting wall i with the paid painter.
                    int nextTime = min(maxTime - 1, t + time[i] + 1);
                    newDp[nextTime] = min(newDp[nextTime], dp[t] + cost[i]);
                }
            }

            dp = newDp; // Update the dp array.
        }

        // The minimum cost is the smallest value in dp[maxTime-1].
        return dp[maxTime - 1];
    }

int main(){
    vector<int> cost = {1,2,3,2};
    vector<int> time = {1,2,3,2};
    int res = paintWalls(cost, time);
    cout<<res;
    return 0;
}