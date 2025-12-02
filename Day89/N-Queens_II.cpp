// // N-Queens II
// // Solved
// // Hard
// // Topics
// // premium lock icon
// // Companies
// // The n-queens puzzle is the problem of placing n queens on an n x n
// chessboard such that no two queens attack each other.

// // Given an integer n, return the number of distinct solutions to the
// n-queens puzzle.

// // Example 1:

// // Input: n = 4
// // Output: 2
// // Explanation: There are two distinct solutions to the 4-queens puzzle as
// shown.
// // Example 2:

// // Input: n = 1
// // Output: 1

// // Constraints:

// // 1 <= n <= 9

// class Solution {
// public:
//     bool queenCanBePlaced(int row, int col, vector<string>& board, int n) {
//         int dupRow = row;
//         int dupCol = col;
//         while (row >= 0 && col >= 0) {
//             if (board[row][col] == 'Q')
//                 return false;
//             row--;
//             col--;
//         }
//         row = dupRow;
//         col = dupCol;

//         while (col >= 0) {
//             if (board[row][col] == 'Q')
//                 return false;
//             col--;
//         }
//         row = dupRow;
//         col = dupCol;

//         while (col >= 0 && row < n) {
//             if (board[row][col] == 'Q')
//                 return false;
//             col--;
//             row++;
//         }
//         return true;
//     }

//     void solve(int col, vector<string>& board, int &ans, int n) {
//         if (col == n) {
//             ans++;
//             return;
//         }

//         for (int row = 0; row < n; row++) {
//             if (queenCanBePlaced(row, col, board, n)) {
//                 board[row][col] = 'Q';
//                 solve(col + 1, board, ans, n);
//                 board[row][col] = '.';
//             }
//         }
//     }
//     int totalNQueens(int n) {
//         int ans= 0;
//         vector<string> board(n);
//         string s(n, '.');
//         for (int i = 0; i < n; i++) {
//             board[i] = s;
//         }
//         solve(0, board, ans, n);
//         return ans;
//     }
// };