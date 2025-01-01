#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> solutions;
        vector<string> board(n, string(n, '.'));
        vector<bool> cols(n, false), diag1(2 * n - 1, false), diag2(2 * n - 1, false);
        backtrack(0, n, board, cols, diag1, diag2, solutions);
        return solutions;
    }

private:
    void backtrack(int row, int n, vector<string>& board, vector<bool>& cols, vector<bool>& diag1, vector<bool>& diag2, vector<vector<string>>& solutions) {
        if (row == n) {
            solutions.push_back(board);
            return;
        }

        for (int col = 0; col < n; ++col) {
            if (cols[col] || diag1[row - col + n - 1] || diag2[row + col]) continue;

            // Place the queen
            board[row][col] = 'Q';
            cols[col] = diag1[row - col + n - 1] = diag2[row + col] = true;

            // Recurse to the next row
            backtrack(row + 1, n, board, cols, diag1, diag2, solutions);

            // Remove the queen
            board[row][col] = '.';
            cols[col] = diag1[row - col + n - 1] = diag2[row + col] = false;
        }
    }
};

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    Solution solution;
    vector<vector<string>> results = solution.solveNQueens(n);

    cout << "Number of solutions: " << results.size() << endl;
    for (const auto& solution : results) {
        for (const auto& row : solution) {
            cout << row << endl;
        }
        cout << endl;
    }

    return 0;
}
