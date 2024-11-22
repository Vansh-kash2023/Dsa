#include<bits/stdc++.h>
using namespace std;

bool canMakeBouquets(const vector<int>& bloomDay, int m, int k, int day) {
    int bouquets = 0;
    int flowers = 0;
    
    for (int i = 0; i < bloomDay.size(); ++i) {
        if (bloomDay[i] <= day) {
            flowers++;
        } else {
            flowers = 0;  // Reset count if flower is not bloomed yet
        }
        
        if (flowers == k) {
            bouquets++;
            flowers = 0;  // Reset flowers count after making a bouquet
        }
    }
    
    return bouquets >= m;
}

int minDays(vector<int>& bloomDay, int m, int k) {
    long long n = bloomDay.size();
    
    // Check if it's even possible to form m bouquets (if m * k > n)
    if ((long long)m * k > n) return -1;  // Use long long for multiplication
    
    int low = 1, high = *max_element(bloomDay.begin(), bloomDay.end());
    int result = -1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (canMakeBouquets(bloomDay, m, k, mid)) {
            result = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    
    return result;
}

int main(){
    vector<int> nums = {1,10,3,10,2};
    int res = minDays(nums, 3, 1);
    cout<<res;
    return 0;
}