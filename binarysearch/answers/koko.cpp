#include<bits/stdc++.h>
using namespace std;

int minEatingSpeed(vector<int>& piles, int h) {
    // Helper function to calculate hours needed at speed k
    auto hoursRequired = [&](int k) -> long long {
        long long hours = 0;
        for (int pile : piles) {
            hours += (pile + k - 1) / k; // Use integer division to round up
        }
        return hours;
    };
    
    int left = 1, right = *max_element(piles.begin(), piles.end());
    int result = right; // Initialize with the max possible speed
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (hoursRequired(mid) <= h) {
            result = mid; // Update the result with the current valid speed
            right = mid - 1; // Try to find a smaller speed
        } else {
            left = mid + 1; // Increase the speed
        }
    }
    
    return result;
}

int main(){
    vector<int> piles = {3,6,7,11};
    int h = 8;
    int res = minEatingSpeed(piles, h);
    cout<<res;
    return 0;
}