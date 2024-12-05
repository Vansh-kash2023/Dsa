#include<bits/stdc++.h>
using namespace std;

bool rotateString(string s, string goal) {
        if (s.length() != goal.length()) {
            return false;
        }
        string concatenated = s + s;
        return concatenated.find(goal) != string::npos;
    }

int main(){
    string s = "abcde";
    string goal = "cdeab";
    bool res = rotateString(s,goal);
    cout<<res;
    return 0;
}