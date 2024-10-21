#include <bits/stdc++.h>
using namespace std;

// int singleNumber(vector<int>& nums) {
//     set<int> Unique(nums.begin(), nums.end());
//     int count = 0;
//     for(auto it:Unique){
//         for(auto iterator:nums){
//             if(it==iterator){
//                 count+=1;
//             }
//         }
//         if(count>1){
//             count=0;
//         }else if(count==1){
//             return it;
//         }
//     }
// }

int singleNumber(vector<int> &nums)
{
    unordered_map<int, int> a;
    for (auto x : nums)
        a[x]++;
    for (auto z : a)
        if (z.second == 1)
            return z.first;
    return -1;
}

int main()
{
    vector<int> nums = {1, 1, 2, 3, 2, 4, 4, 5, 5};
    int res = singleNumber(nums);
    cout << res;
    return 0;
}