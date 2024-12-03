#include<bits/stdc++.h>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return ""; // No strings in the input
        
        // Start with the first string as the prefix
        string prefix = strs[0];
        
        for (int i = 1; i < strs.size(); ++i) {
            // Reduce prefix until it matches the beginning of strs[i]
            while (strs[i].find(prefix) != 0) {
                prefix = prefix.substr(0, prefix.size() - 1);
                if (prefix.empty()) return ""; // No common prefix
            }
        }
        
        return prefix;
    }

int main(){
    vector <string> s = {"flower","flow","flight"};
    string res = longestCommonPrefix(s);
    cout<<res;
    return 0;
}