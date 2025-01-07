#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (char ch : s) {
            // Push opening brackets onto the stack
            if (ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
            }
            // Check closing brackets
            else if (ch == ')' || ch == '}' || ch == ']') {
                if (st.empty()) return false; // No matching opening bracket
                char top = st.top();
                st.pop();
                // Check if the top matches the closing bracket
                if ((ch == ')' && top != '(') ||
                    (ch == '}' && top != '{') ||
                    (ch == ']' && top != '[')) {
                    return false;
                }
            }
        }

        // If the stack is empty, the string is valid
        return st.empty();
    }
};

int main() {
    Solution solution;

    // Test cases
    string test1 = "()";
    string test2 = "()[]{}";
    string test3 = "(]";
    string test4 = "([])";

    cout << "Test 1: " << solution.isValid(test1) << endl; // Expected output: true
    cout << "Test 2: " << solution.isValid(test2) << endl; // Expected output: true
    cout << "Test 3: " << solution.isValid(test3) << endl; // Expected output: false
    cout << "Test 4: " << solution.isValid(test4) << endl; // Expected output: true

    return 0;
}
