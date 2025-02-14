#include<bits/stdc++.h>
using namespace std;

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();       // Number of rows
        int n = matrix[0].size();    // Number of columns
        int left = 0, right = m * n - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            int midValue = matrix[mid / n][mid % n]; // Convert 1D index to 2D indices

            if (midValue == target) {
                return true;
            } else if (midValue < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return false;
    }



int main(){
    vector<vector<int>> matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    int target = 3; 
    bool res = searchMatrix(matrix, target);
    cout<<res;
    return 0;
}