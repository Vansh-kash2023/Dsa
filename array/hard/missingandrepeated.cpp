#include<bits/stdc++.h>
using namespace std;

vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
    int n = grid.size();
    int maxVal = n * n;
    vector<int> count(maxVal + 1, 0);
    int repeated = -1, missing = -1;

    // Flatten the grid and count occurrences of each number
    for (const auto& row : grid) {
        for (int num : row) {
            count[num]++;
        }
    }

    // Identify the repeated and missing numbers
    for (int i = 1; i <= maxVal; ++i) {
        if (count[i] == 2) {
            repeated = i;
        } else if (count[i] == 0) {
            missing = i;
        }
    }

    return {repeated, missing};
}

int main(){
    vector<vector<int>> grid = {{1,3},{2,2}};
    vector<int> res = findMissingAndRepeatedValues(grid);
    for(auto it:res){
        cout<<it<<" ";
    }
    return 0;
}