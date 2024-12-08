#include<bits/stdc++.h>
using namespace std;

int maxDepth(string s) {
        int currentDepth = 0; // Tracks the current depth of parentheses
        int maxDepth = 0;     // Stores the maximum depth encountered

        for (char c : s) {
            if (c == '(') {
                currentDepth++;           // Increase depth on opening parenthesis
                maxDepth = max(maxDepth, currentDepth); // Update maxDepth
            } else if (c == ')') {
                currentDepth--;           // Decrease depth on closing parenthesis
            }
        }
        return maxDepth;
    }

int main(){
    string s = "(1+(2*3)+((8)/4))+1";
    int res = maxDepth(s);
    cout<<res;
    return 0;
}