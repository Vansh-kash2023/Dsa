#include<bits/stdc++.h>
using namespace std;

string longestPalinSubstring(string str) {
    int n = str.length();
    if (n == 0) return "";

    int start = 0, maxLength = 1;

    auto expandAroundCenter = [&](int left, int right) {
        while (left >= 0 && right < n && str[left] == str[right]) {
            int currentLength = right - left + 1;
            if (currentLength > maxLength) {
                maxLength = currentLength;
                start = left;
            }
            left--;
            right++;
        }
    };

    for (int i = 0; i < n; i++) {
        expandAroundCenter(i, i);

        expandAroundCenter(i, i + 1);
    }

    return str.substr(start, maxLength);
}


int main(){
    string str="ababc";
    string res = longestPalinSubstring(str);
    cout<<res;
    return 0;
}