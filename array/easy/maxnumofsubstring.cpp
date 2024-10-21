#include<bits/stdc++.h>
using namespace std;

// Approach 1
// int backtrack(string& str, int start, unordered_set<string>& seen) {
//     if (start == str.length()) return 0;  // Base case: reached the end of the string
    
//     int maxSplits = 0;  // To store the maximum unique splits

//     for (int end = start; end < str.length(); ++end) {
//         string substr = str.substr(start, end - start + 1);  // Extract substring from `start` to `end`

//         if (seen.find(substr) == seen.end()) {  // If the substring hasn't been used before
//             seen.insert(substr);  // Add the substring to the set of seen substrings
//             maxSplits = max(maxSplits, 1 + backtrack(str, end + 1, seen));  // Recur and count the splits
//             seen.erase(substr);  // Backtrack by removing the current substring from the set
//         }
//     }

//     return maxSplits;  // Return the maximum number of unique splits
// }

// int maxUniqueSplit(string str) {
//     unordered_set<string> seen;  // To track unique substrings
//     return backtrack(str, 0, seen);  // Start backtracking from index 0
// }

// Approach 2
int maxUniqueSplit(string str) {
    unordered_set<string> seen;  // Set to store unique substrings
    string current = "";  // To store the current substring we're forming
    int count = 0;  // To count the number of unique substrings

    // Loop through each character in the string
    for (char ch : str) {
        current += ch;  // Add the current character to the substring

        // If the current substring is not seen, we "split" here
        if (seen.find(current) == seen.end()) {
            seen.insert(current);  // Mark the current substring as seen
            count++;  // Increase the count of unique substrings
            current = "";  // Reset the current substring to start a new one
        }
    }

    return count;  // Return the total number of unique substrings
}

int main(){
    string s = "aabbaab";
    int res = maxUniqueSplit(s);
    cout<<res;
    return 0;
}