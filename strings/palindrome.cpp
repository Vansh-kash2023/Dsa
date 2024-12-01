#include<bits/stdc++.h>
using namespace std;

string reverseWords(string s) {
        vector<string> words;
        string word = "", result = "";

        int i = 0, n = s.size();
        while (i < n && s[i] == ' ') ++i; 
        while (n > i && s[n - 1] == ' ') --n; 

        for (; i < n; ++i) {
            if (s[i] != ' ') {
                word += s[i];
            } else if (!word.empty()) {
                words.push_back(word);
                word = "";
            }
        }
        if (!word.empty()) words.push_back(word);

        for (int j = words.size() - 1; j >= 0; --j) {
            result += words[j];
            if (j > 0) result += " ";
        }

        return result;
    }

int main(){
    string s = "aabbaa";
    string res = reverseWords(s);
    cout<<res;
    return 0;
}