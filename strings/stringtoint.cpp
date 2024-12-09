#include<bits/stdc++.h>
using namespace std;

int myAtoi(string s) {
        int n = s.length();
        int i = 0;

        // Step 1: Skip leading whitespace
        while (i < n && s[i] == ' ') {
            i++;
        }

        // Step 2: Check for '+' or '-' to determine sign
        int sign = 1;
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        // Step 3: Read digits and form the number
        long result = 0;
        while (i < n && isdigit(s[i])) {
            result = result * 10 + (s[i] - '0');
            i++;

            // Step 4: Check for overflow
            if (result * sign > INT_MAX) return INT_MAX;
            if (result * sign < INT_MIN) return INT_MIN;
        }

        return static_cast<int>(result * sign);
    }

int main(){
    string s = "42";
    int res = myAtoi(s);
    cout<<res;
    return 0;
}