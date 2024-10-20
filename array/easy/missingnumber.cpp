#include<bits/stdc++.h>
using namespace std;

int missingNumber(vector<int>& nums) {
    int length = nums.size();
    
    int expected_sum = length * (length + 1) / 2;

    int actual_sum = 0;
    for (int num : nums) {
        actual_sum += num;
    }

    return expected_sum - actual_sum;
}


// Approach 2
// int missingNumber(vector<int>& nums) {
//     int length = nums.size();
    
//     // Create a set with all numbers from 0 to length
//     set<int> fullSet;
//     for (int i = 0; i <= length; i++) {
//         fullSet.insert(i);
//     }
    
//     // Remove all elements present in nums
//     for (int num : nums) {
//         fullSet.erase(num);
//     }
    
//     // The remaining element in the set is the missing number
//     return *fullSet.begin();
// }


int main(){
    vector<int> in = {0,1,2,3,4,6,7,8};
    int res = missingNumber(in);
    cout<<res;
    return 0;
}