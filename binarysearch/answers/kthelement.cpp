#include<bits/stdc++.h>
using namespace std;

int kthElement(vector<int> &arr1, vector<int>& arr2, int n, int m, int k) {
    if (n > m) {
        return kthElement(arr2, arr1, m, n, k);
    }
    
    int left = max(0, k - m), right = min(k, n);
    
    while (left <= right) {
        int cut1 = left + (right - left) / 2; 
        int cut2 = k - cut1; 
        
        int left1 = (cut1 == 0) ? INT_MIN : arr1[cut1 - 1];
        int left2 = (cut2 == 0) ? INT_MIN : arr2[cut2 - 1];
        int right1 = (cut1 == n) ? INT_MAX : arr1[cut1];
        int right2 = (cut2 == m) ? INT_MAX : arr2[cut2];
        
        if (left1 <= right2 && left2 <= right1) {
            return max(left1, left2);
        } else if (left1 > right2) {
            right = cut1 - 1;
        } else {
            left = cut1 + 1;
        }
    }
    
    return -1; 
}


int main(){
    vector<int> arr1 = {2, 3, 45};   
    vector<int> arr2 = {4, 6, 7, 8};
    int n = 3;
    int m = 4;
    int k = 4;
    int res = kthElement(arr1, arr2, n, m,k);
    cout<<res;
    return 0;
}