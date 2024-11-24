#include<bits/stdc++.h>
using namespace std;

bool canShip(vector<int>& weights, int days, int capacity) {
    int currentWeight = 0;
    int requiredDays = 1;
    
    for (int weight : weights) {
        if (currentWeight + weight > capacity) {
            // Start a new day
            requiredDays++;
            currentWeight = weight;
            if (requiredDays > days) {
                return false; // Too many days needed
            }
        } else {
            currentWeight += weight;
        }
    }
    return true;
}

int shipWithinDays(vector<int>& weights, int days) {
    int left = *max_element(weights.begin(), weights.end()); // Minimum capacity
    int right = accumulate(weights.begin(), weights.end(), 0); // Maximum capacity
    int result = right;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (canShip(weights, days, mid)) {
            result = mid; // Try to minimize the capacity
            right = mid - 1;
        } else {
            left = mid + 1; // Increase capacity
        }
    }

    return result;
}

int main(){
    vector<int> wieghts = {1,2,3,4,5,6,7,8,9,10};
    int days = 5;
    int res = shipWithinDays(wieghts, days);
    cout<<res;
    return 0;
}