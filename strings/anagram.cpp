#include<bits/stdc++.h>
using namespace std;

bool isAnagram(string s, string t) {
        // If the lengths are different, they can't be anagrams
        if (s.length() != t.length()) {
            return false;
        }
        
        // Create a frequency count array for English lowercase letters
        vector<int> freq(26, 0);
        
        // Increment frequency for characters in `s` and decrement for `t`
        for (int i = 0; i < s.length(); ++i) {
            freq[s[i] - 'a']++;
            freq[t[i] - 'a']--;
        }
        
        // Check if all frequencies are zero
        for (int count : freq) {
            if (count != 0) {
                return false;
            }
        }
        
        return true;
    }

int main(){
    string s = "anagram";
    string t = "nagaram";
    bool res = isAnagram(s,t);
    cout<<res;
    return 0;
}