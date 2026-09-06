// // 64. Minimum Path Sum
// // Solved
// // Medium
// // Topics
// // premium lock icon
// // Companies
// // Given a m x n grid filled with non-negative numbers, find a path from top
// // left to bottom right, which minimizes the sum of all numbers along its
// path.

// // Note: You can only move either down or right at any point in time.

// // Example 1:

// // Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
// // Output: 7
// // Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.
// // Example 2:

// // Input: grid = [[1,2,3],[4,5,6]]
// // Output: 12

// // Constraints:

// // m == grid.length
// // n == grid[i].length
// // 1 <= m, n <= 200
// // 0 <= grid[i][j] <= 200

// class Solution {
// public:
//     int recursionSol(vector<vector<int>>& grid, int i, int j) {
//         if (i == 0 && j == 0) {
//             return grid[i][j];
//         }
//         if (i < 0 || j < 0) {
//             return INT_MAX;
//         }

//         int up = recursionSol(grid, i - 1, j);
//         int left = recursionSol(grid, i, j - 1);
//         return grid[i][j] + min(up, left);
//     }

//     int memoizationSol(vector<vector<int>>& grid, int i, int j,
//                        vector<vector<int>>& dp) {
//         if (i == 0 && j == 0) {
//             return grid[i][j];
//         }
//         if (i < 0 || j < 0) {
//             return INT_MAX;
//         }
//         if (dp[i][j] != -1) {
//             return dp[i][j];
//         }

//         int up = memoizationSol(grid, i - 1, j, dp);
//         int left = memoizationSol(grid, i, j - 1, dp);
//         return dp[i][j] = grid[i][j] + min(up, left);
//     }
//     int tabulationSol(vector<vector<int>>& grid, int n, int m,
//                       vector<vector<int>>& dp) {

//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < m; j++) {
//                 if (i == 0 && j == 0) {
//                     dp[i][j] = grid[i][j];
//                 } else {
//                     int up = INT_MAX;   // Neglected if i is lesser than zero
//                     int left = INT_MAX; // Neglected if j is lesser than zero
//                     if (i > 0) {
//                         up = grid[i][j] + dp[i - 1][j];
//                     }
//                     if (j > 0) {
//                         left = grid[i][j] + dp[i][j - 1];
//                     }
//                     dp[i][j] = min(up, left);
//                 }
//             }
//         }

//         return dp[n - 1][m - 1];
//     }
//     int spaceOptimizationSol(vector<vector<int>>& grid, int n, int m) {
//         vector<int> curr(m, 0);
//         vector<int> prev(m, 0);
//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < m; j++) {
//                 if (i == 0 && j == 0) {
//                     curr[j] = grid[i][j];
//                 } else {
//                     int up = INT_MAX;   // Neglected if i is lesser than zero
//                     int left = INT_MAX; // Neglected if j is lesser than zero
//                     if (i > 0) {
//                         up = grid[i][j] + prev[j];
//                     }
//                     if (j > 0) {
//                         left = grid[i][j] + curr[j - 1];
//                     }
//                     curr[j] = min(up, left);
//                 }
//             }
//             prev = curr;
//         }

//         return prev[m - 1];
//     }

//     int minPathSum(vector<vector<int>>& grid) {
//         int n = grid.size();
//         int m = grid[0].size();
//         // return recursionSol(grid, n - 1, m - 1); // TLE
//         // vector<vector<int>> dp(n, vector<int>(m, -1));
//         // return memoizationSol(grid, n - 1, m - 1, dp); // Works
//         // vector<vector<int>> dp2(n, vector<int>(m, -0));
//         // return tabulationSol(grid, n, m, dp2); // Works
//         return spaceOptimizationSol(grid, n, m);
//     }
// };