#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> result;
        if (num.empty()) return result;
        
        function<void(int, long, long, string)> backtrack = [&](int index, long currentValue, long previousValue, string expression) {
            if (index == num.size()) {
                if (currentValue == target) {
                    result.push_back(expression);
                }
                return;
            }
            
            for (int i = index; i < num.size(); ++i) {
                string currentStr = num.substr(index, i - index + 1);
                long currentNum = stol(currentStr);
                
                if (currentStr.size() > 1 && currentStr[0] == '0') break;

                if (index == 0) {
                    backtrack(i + 1, currentNum, currentNum, currentStr);
                } else {
                    backtrack(i + 1, currentValue + currentNum, currentNum, expression + "+" + currentStr);
                    backtrack(i + 1, currentValue - currentNum, -currentNum, expression + "-" + currentStr);
                    backtrack(i + 1, currentValue - previousValue + (previousValue * currentNum), previousValue * currentNum, expression + "*" + currentStr);
                }
            }
        };
        
        backtrack(0, 0, 0, "");
        return result;
    }
};

int main() {
    Solution solution;
    string num;
    int target;

    // Input the number string and target value
    cout << "Enter the number string: ";
    cin >> num;
    cout << "Enter the target value: ";
    cin >> target;

    // Call the function and get the result
    vector<string> results = solution.addOperators(num, target);

    // Output the results
    cout << "Expressions that evaluate to the target:\n";
    if (results.empty()) {
        cout << "No valid expressions found.\n";
    } else {
        for (const string& expr : results) {
            cout << expr << endl;
        }
    }

    return 0;
}
