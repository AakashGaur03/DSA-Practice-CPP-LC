// // Surrounded Regions
// // Solved
// // Medium
// // Topics
// // premium lock icon
// // Companies
// // You are given an m x n matrix board containing letters 'X' and 'O',
// capture
// // regions that are surrounded:

// // Connect: A cell is connected to adjacent cells horizontally or vertically.
// // Region: To form a region connect every 'O' cell.
// // Surround: A region is surrounded if none of the 'O' cells in that region
// are
// // on the edge of the board. Such regions are completely enclosed by 'X'
// cells.
// // To capture a surrounded region, replace all 'O's with 'X's in-place within
// // the original board. You do not need to return anything.

// // Example 1:

// // Input: board =
// // [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]

// // Output:
// // [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]

// // Explanation:

// // In the above diagram, the bottom region is not captured because it is on
// the
// // edge of the board and cannot be surrounded.

// // Example 2:

// // Input: board = [["X"]]

// // Output: [["X"]]

// class Solution {
// public:
//     void dfs(int row, int col, vector<vector<int>>& vis,
//              vector<vector<char>>& mat) {
//         vis[row][col] = 1;
//         int n = mat.size();
//         int m = mat[0].size();

//         int delRow[] = {-1, 0, +1, 0};
//         int delCol[] = {0, 1, 0, -1};

//         for (int i = 0; i < 4; i++) {
//             int nrow = row + delRow[i];
//             int ncol = col + delCol[i];

//             if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
//                 !vis[nrow][ncol] && mat[nrow][ncol] == 'O') {
//                 vis[nrow][ncol] = 1;
//                 dfs(nrow, ncol, vis, mat);
//             }
//         }
//     }

//     void solve(vector<vector<char>>& board) {
//         int n = board.size();
//         int m = board[0].size();
//         vector<vector<int>> vis(n, vector<int>(m, 0));

//         for (int i = 0; i < n; i++) {
//             // Traverse First Col and Last Col
//             if (!vis[i][0] && board[i][0] == 'O') {
//                 // First Col
//                 dfs(i, 0, vis, board);
//             }
//             if (!vis[i][m-1] && board[i][m-1] == 'O') {
//                 // Last Col
//                 dfs(i,m-1, vis, board);
//             }
//         }
//         for (int j = 0; j < m; j++) {
//             // Traverse First Row and Last Row
//             if (!vis[0][j] && board[0][j] == 'O') {
//                 // First Row
//                 dfs(0, j, vis, board);
//             }
//             if (!vis[n-1][j] && board[n-1][j] == 'O') {
//                 // Last Row
//                 dfs(n-1,j, vis, board);
//             }
//         }

//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < m; j++) {
//                 if (!vis[i][j] && board[i][j] == 'O') {
//                     board[i][j] = 'X';
//                 }
//             }
//         }
//     }
// };