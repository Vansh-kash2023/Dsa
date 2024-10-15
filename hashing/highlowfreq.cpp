#include<bits/stdc++.h>

using namespace std;

vector<int> getFrequencies(vector<int>& v) {
    unordered_map<int, int> frequencyMap;

    // Count frequencies of each element
    for (int num : v) {
        frequencyMap[num]++;
    }

    int highestFrequency = 0;
    int lowestFrequency = INT_MAX;
    int highestFreqElement = INT_MAX;
    int lowestFreqElement = INT_MAX;

    // Find the highest and lowest frequency elements
    for (const auto& entry : frequencyMap) {
        int element = entry.first;
        int frequency = entry.second;

        // Check for highest frequency
        if (frequency > highestFrequency) {
            highestFrequency = frequency;
            highestFreqElement = element;
        } else if (frequency == highestFrequency) {
            highestFreqElement = min(highestFreqElement, element);
        }

        // Check for lowest frequency
        if (frequency < lowestFrequency) {
            lowestFrequency = frequency;
            lowestFreqElement = element;
        } else if (frequency == lowestFrequency) {
            lowestFreqElement = min(lowestFreqElement, element);
        }
    }

    return {highestFreqElement, lowestFreqElement};
}


int main() {
    vector<int> v = {1, 2, 3, 1, 1, 4};
    vector<int> result = getFrequencies(v);
    cout << result[0] << " " << result[1] << endl; // Output: 1 2
    return 0;
}