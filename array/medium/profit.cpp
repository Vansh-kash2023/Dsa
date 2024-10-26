#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& prices) {
        int buy = prices[0];
        int profit = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] < buy) {
                buy = prices[i];
            } else if (prices[i] - buy > profit) {
                profit = prices[i] - buy;
            }
        }
        return profit;
    }

int main(){
    vector<int> prices = {1,5,1,3};
    int res = maxProfit(prices);
    cout<<res;
    return 0;
}