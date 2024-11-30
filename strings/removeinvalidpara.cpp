#include <bits/stdc++.h>
using namespace std;

bool isValid(string s) {
    int balance = 0;
    for (char c : s) {
        if (c == '(') {
            balance++;
        } else if (c == ')') {
            balance--;
        }
        if (balance < 0) return false; // More ')' than '('
    }
    return balance == 0; // All '(' and ')' are balanced
}

vector<string> removeInvalidParentheses(string &str) {
    vector<string> result;
    unordered_set<string> visited; // To avoid duplicates
    queue<string> q;
    
    q.push(str);
    visited.insert(str);
    bool foundValid = false;

    while (!q.empty()) {
        string current = q.front();
        q.pop();

        if (isValid(current)) {
            result.push_back(current);
            foundValid = true;
        }
        
        if (foundValid) continue; // Stop exploring further once valid strings are found

        for (int i = 0; i < current.size(); i++) {
            if (current[i] != '(' && current[i] != ')') continue;
            string next = current.substr(0, i) + current.substr(i + 1); // Remove the i-th character
            if (visited.find(next) == visited.end()) {
                visited.insert(next);
                q.push(next);
            }
        }
    }

    return result;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        vector<string> result = removeInvalidParentheses(str);
        for (string res : result) {
            cout << res << " ";
        }
        cout << endl;
    }
    return 0;
}
