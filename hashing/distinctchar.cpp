#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

int minOperationsToKDistinct(int n, string s, int k) {
    // Count the frequency of each character in the string
    unordered_map<char, int> charCount;
    for (char c : s) {
        charCount[c]++;
    }

    // Get the number of distinct characters currently in the string
    int distinctCharCount = charCount.size();

    if (distinctCharCount == k) {
        // If the number of distinct characters is already K, no operations are needed
        return 0;
    } else if (distinctCharCount > k) {
        // If we have more distinct characters than needed, we need to reduce them
        vector<int> frequencies;
        for (auto& pair : charCount) {
            frequencies.push_back(pair.second);
        }

        // Sort frequencies in ascending order
        sort(frequencies.begin(), frequencies.end());

        // Remove characters until we have exactly K distinct characters
        int operations = 0;
        int i = 0;
        while (distinctCharCount > k) {
            operations += frequencies[i];
            distinctCharCount--;
            i++;
        }

        return operations;
    } else {
        // If we have fewer distinct characters than needed, we need to add new ones
        // Calculate how many additional distinct characters are required
        int additionalDistinct = k - distinctCharCount;

        // Adding new distinct characters requires replacing existing ones
        // The minimum operations needed is exactly the additional distinct count
        return additionalDistinct;
    }
}

int main() {
    int N = 9;
    string s = "ndknndaaa";
    int K = 2;

    int result = minOperationsToKDistinct(N, s, K);
    cout << result << endl;

    return 0;
}
