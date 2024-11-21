#include<bits/stdc++.h>
using namespace std;

pair<int, int> getFloorAndCeil(vector<int> &a, int n, int x) {
    int low = 0, high = n - 1;
    int floor = -1, ceil = -1;

    // Finding floor
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (a[mid] <= x) {
            floor = a[mid]; // Update floor
            low = mid + 1;  // Search in the right half
        } else {
            high = mid - 1; // Search in the left half
        }
    }

    // Reset pointers for ceiling
    low = 0, high = n - 1;

    // Finding ceiling
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (a[mid] >= x) {
            ceil = a[mid]; // Update ceil
            high = mid - 1; // Search in the left half
        } else {
            low = mid + 1; // Search in the right half
        }
    }

    return {floor, ceil};
}

int main(){
    vector<int> a = {3,4,7,8,8,10};
    pair<int,int> res = getFloorAndCeil(a, 6, 5);
    cout<<res.first<<endl;
    cout<<res.second;
    return 0;
}