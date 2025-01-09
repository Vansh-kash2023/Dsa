#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        // Map to store the next greater element for each number in nums2
        unordered_map<int, int> nextGreaterMap;
        stack<int> s; // Monotonic stack to find next greater elements

        // Traverse nums2 from right to left
        for (int i = nums2.size() - 1; i >= 0; --i) {
            int num = nums2[i];
            // Remove elements from the stack that are less than or equal to the current number
            while (!s.empty() && s.top() <= num) {
                s.pop();
            }
            // If the stack is not empty, the top element is the next greater element
            nextGreaterMap[num] = s.empty() ? -1 : s.top();
            // Push the current number onto the stack
            s.push(num);
        }

        // Create the result vector for nums1
        vector<int> result;
        for (int num : nums1) {
            result.push_back(nextGreaterMap[num]);
        }
        return result;
    }
};

int main() {
    Solution solution;

    // Example 1
    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};
    vector<int> result = solution.nextGreaterElement(nums1, nums2);

    cout << "Example 1 Output: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    // Example 2
    nums1 = {2, 4};
    nums2 = {1, 2, 3, 4};
    result = solution.nextGreaterElement(nums1, nums2);

    cout << "Example 2 Output: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
