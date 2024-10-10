#include <bits/stdc++.h>
using namespace std;
// bool checkPalindrome(string s)
// {
//     // Write your code here.
//     vector<char> newchar;
//     for(int i = 0; i<s.length(); i++){
//         newchar.push_back(s[i]);
//     }

//     reverse(newchar.begin(), newchar.end());

//     string reversedstr(newchar.begin(), newchar.end());

//     if(s==reversedstr){
//         return true;
//     }else{
//         return false;
//     }

//     // for(auto it:newchar){
//     //     cout<<it<<" ";
//     // }
// }

bool checkPalindrome(string s)
{
    // Write your code here.
    int n = s.length();
    
    // Compare characters from the start and the end of the string
    for (int i = 0; i < n / 2; i++) {
        if (s[i] != s[n - i - 1]) {
            return false; // If a mismatch is found, it's not a palindrome
        }
    }
    
    return true; 
}


int main(){
    bool res = checkPalindrome("c1 O$d@eeD o1c");
    cout<<res;
    return 0; 
}