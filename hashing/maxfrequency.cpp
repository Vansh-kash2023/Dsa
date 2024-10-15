#include<bits/stdc++.h>
using namespace std;

int maximumFrequency(vector<int> &arr, int n)
{
    unordered_map<int, int> frequency;
    unordered_map<int, int> firstIndex;
    int maxFreq = 0;
    int result = -1;

    for (int i = 0; i < arr.size(); ++i) {
        frequency[arr[i]]++;
        
        
        if (firstIndex.find(arr[i]) == firstIndex.end()) {
            firstIndex[arr[i]] = i;
        }

        
        if (frequency[arr[i]] > maxFreq || 
            (frequency[arr[i]] == maxFreq && firstIndex[arr[i]] < firstIndex[result])) {
            maxFreq = frequency[arr[i]]; 
            result = arr[i];
        }
    }

    return result;
}

int main() {
    vector<int> arr = {1, 2, 2, 3, 4, 4, 4, 4, 5, 6, 7};
    int result = maximumFrequency(arr, 8);
    cout << "Maximum frequency: " << result << endl; // Output the result
    return 0;
}
