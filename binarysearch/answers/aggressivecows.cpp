#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool canPlaceCows(vector<int>& stalls, int k, int minDist) {
    int count = 1;  // Place the first cow in the first stall
    int lastPosition = stalls[0];
    
    for (int i = 1; i < stalls.size(); i++) {
        if (stalls[i] - lastPosition >= minDist) {
            count++;
            lastPosition = stalls[i];
            if (count == k) return true;  // If we've placed all k cows, return true
        }
    }
    return false;  // If we couldn't place all cows
}

int aggressiveCows(vector<int>& stalls, int k) {
    sort(stalls.begin(), stalls.end());  // Sort the stall positions
    
    int left = 1;  // Minimum possible distance
    int right = stalls.back() - stalls.front();  // Maximum possible distance
    
    int result = 0;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (canPlaceCows(stalls, k, mid)) {
            result = mid;  // Mid is a feasible solution, try for a larger distance
            left = mid + 1;
        } else {
            right = mid - 1;  // Mid is not feasible, try a smaller distance
        }
    }
    
    return result;
}

int main() {
    vector<int> stalls = {1, 2, 3};
    int k = 2;
    cout << "Maximum possible minimum distance: " << aggressiveCows(stalls, k) << endl;
    return 0;
}
