#include<bits/stdc++.h>
using namespace std;

int findMaxConsecutiveOnes(vector<int>& nums) {
    int count = 0, maxCount = 0;
    
    for (auto it : nums) {
        if (it == 1) {
            count++;
        } else {
            maxCount = max(maxCount, count);
            count = 0;
        }
    }
    maxCount = max(maxCount, count);
    
    return maxCount;
    }

int main(){
    vector<int> arr = {1,1,1,5,3,1,1,2,1,1,1,1,1,1};
    int res = findMaxConsecutiveOnes(arr);
    cout<<res;
    return 0;
}