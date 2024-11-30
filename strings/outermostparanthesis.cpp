#include<bits/stdc++.h>
using namespace std;

string removeOuterParentheses(string s) {
        string result;  // To store the final string
        int count = 0;  // To track the balance of parentheses
        
        for (char c : s) {
            if (c == '(') {
                if (count > 0) {
                    result += c;  // Add to result only if it's not an outer '('
                }
                count++;  // Increment the balance
            } else if (c == ')') {
                count--;  // Decrement the balance
                if (count > 0) {
                    result += c;  // Add to result only if it's not an outer ')'
                }
            }
        }
        return result;
    }

int main(){
    string s = "(()())(())";
    string res = removeOuterParentheses(s);
    cout<<res;
    return 0;
}