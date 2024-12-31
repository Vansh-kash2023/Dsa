#include <bits/stdc++.h>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();
        
        // Lambda function for backtracking
        function<bool(int, int, int)> backtrack = [&](int r, int c, int index) {
            if (index == word.size()) return true; // All characters matched
            
            // Check boundary conditions and if the cell matches the current character
            if (r < 0 || c < 0 || r >= rows || c >= cols || board[r][c] != word[index]) 
                return false;

            // Mark the cell as visited
            char temp = board[r][c];
            board[r][c] = '#';

            // Explore all 4 possible directions
            bool found = backtrack(r + 1, c, index + 1) || 
                         backtrack(r - 1, c, index + 1) || 
                         backtrack(r, c + 1, index + 1) || 
                         backtrack(r, c - 1, index + 1);

            // Restore the cell value
            board[r][c] = temp;

            return found;
        };

        // Try to start the search from every cell
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (backtrack(i, j, 0)) return true;
            }
        }

        return false;
    }
};

int main() {
    Solution sol;
    vector<vector<char>> board1 = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}
    };
    string word1 = "ABCCED";
    string word2 = "SEE";
    string word3 = "ABCB";

    cout << boolalpha; // Print bools as true/false
    cout << "Word " << word1 << " exists: " << sol.exist(board1, word1) << endl;
    cout << "Word " << word2 << " exists: " << sol.exist(board1, word2) << endl;
    cout << "Word " << word3 << " exists: " << sol.exist(board1, word3) << endl;

    return 0;
}
