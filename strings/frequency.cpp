#include<bits/stdc++.h>
using namespace std;

string frequencySort(string s) {
        unordered_map<char, int> freqMap;
        for (char c : s) {
            freqMap[c]++;
        }
        
        vector<pair<int, char>> freqVec;
        for (auto& entry : freqMap) {
            freqVec.push_back({entry.second, entry.first});
        }
        
        sort(freqVec.begin(), freqVec.end(), [](pair<int, char>& a, pair<int, char>& b) {
            return a.first > b.first; 
        });
        
        string result;
        for (auto& entry : freqVec) {
            result += string(entry.first, entry.second);
        }
        
        return result;
    }

int main(){
    string s = "tree";
    string res = frequencySort(s);
    cout<<res;
    return 0;
}