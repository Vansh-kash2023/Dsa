#include<bits/stdc++.h>
using namespace std;

// Clockwise
void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();
    
    // Step 1: Transpose the matrix
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    
    // Step 2: Reverse each row
    for (int i = 0; i < n; ++i) {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}

// AntiClockwise
void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();

    // Step 1: Transpose the matrix
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    // Step 2: Reverse each column
    for (int j = 0; j < n; ++j) {
        for (int i = 0, k = n - 1; i < k; ++i, --k) {
            swap(matrix[i][j], matrix[k][j]);
        }
    }
}

int main(){
    vector<vector<int>> matrix = {{1,2,3}, {4,5,6}, {7,8,9}};
    rotate(matrix);
    for(auto it:matrix){
        for(auto e:it){
            cout<<e<<" ";
        }
        cout<<endl;
    }
    return 0;
}