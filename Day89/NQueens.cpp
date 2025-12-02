// // N-Queens
// // Solved
// // Hard
// // Topics
// // premium lock icon
// // Companies
// // The n-queens puzzle is the problem of placing n queens on an n x n
// chessboard such that no two queens attack each other.

// // Given an integer n, return all distinct solutions to the n-queens puzzle.
// You may return the answer in any order.

// // Each solution contains a distinct board configuration of the n-queens'
// placement, where 'Q' and '.' both indicate a queen and an empty space,
// respectively.

// // Example 1:

// // Input: n = 4
// // Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
// // Explanation: There exist two distinct solutions to the 4-queens puzzle as
// shown above
// // Example 2:

// // Input: n = 1
// // Output: [["Q"]]

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

//     void solve(int col, vector<string>& board, vector<vector<string>>& ans,
//     int n) {
//         if (col == n) {
//             ans.push_back(board);
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
//     vector<vector<string>> solveNQueens(int n) {
//         vector<vector<string>> ans;
//         vector<string> board(n);
//         string s(n, '.');
//         for (int i = 0; i < n; i++) {
//             board[i] = s;
//         }
//         solve(0, board, ans, n);
//         return ans;
//     }
// };