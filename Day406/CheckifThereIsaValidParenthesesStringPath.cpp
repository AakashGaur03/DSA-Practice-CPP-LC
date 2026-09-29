// // 2267. Check if There Is a Valid Parentheses String Path
// // Solved
// // Hard
// // Topics
// // premium lock icon
// // Companies
// // Hint
// // A parentheses string is a non-empty string consisting only of '(' and ')'.
// It
// // is valid if any of the following conditions is true:

// // It is ().
// // It can be written as AB (A concatenated with B), where A and B are valid
// // parentheses strings. It can be written as (A), where A is a valid
// parentheses
// // string. You are given an m x n matrix of parentheses grid. A valid
// // parentheses string path in the grid is a path satisfying all of the
// following
// // conditions:

// // The path starts from the upper left cell (0, 0).
// // The path ends at the bottom-right cell (m - 1, n - 1).
// // The path only ever moves down or right.
// // The resulting parentheses string formed by the path is valid.
// // Return true if there exists a valid parentheses string path in the grid.
// // Otherwise, return false.

// // Example 1:

// // Input: grid = [["(","(","("],[")","(",")"],["(","(",")"],["(","(",")"]]
// // Output: true
// // Explanation: The above diagram shows two possible paths that form valid
// // parentheses strings. The first path shown results in the valid parentheses
// // string "()(())". The second path shown results in the valid parentheses
// // string "((()))". Note that there may be other valid parentheses string
// paths.
// // Example 2:

// // Input: grid = [[")",")"],["(","("]]
// // Output: false
// // Explanation: The two possible paths form the parentheses strings "))(" and
// // ")((". Since neither of them are valid parentheses strings, we return
// false.

// // Constraints:

// // m == grid.length
// // n == grid[i].length
// // 1 <= m, n <= 100
// // grid[i][j] is either '(' or ')'.

// class Solution {
// public:
//     int recursionSol(int i, int j, int openCount, vector<vector<char>>& grid)
//     {

//         int m = grid.size();
//         int n = grid[0].size();

//         // Out of bounds
//         if (i >= m || j >= n) {
//             return false;
//         }

//         // Update openCount
//         if (grid[i][j] == '(') {
//             openCount++;
//         } else {
//             openCount--;
//         }

//         // Invalid state
//         if (openCount < 0) {
//             return false;
//         }

//         // Destination
//         if (i == m - 1 && j == n - 1) {
//             return openCount == 0;
//         }

//         bool down = recursionSol(i + 1, j, openCount, grid);
//         bool right = recursionSol(i, j + 1, openCount, grid);

//         return down || right;
//     }

//     int memoizationSol(int i, int j, int openCount, vector<vector<char>>&
//     grid,
//                        vector<vector<vector<int>>>& dp) {

//         int m = grid.size();
//         int n = grid[0].size();

//         // Out of bounds
//         if (i >= m || j >= n) {
//             return false;
//         }

//         // Update openCount based on current cell
//         if (grid[i][j] == '(') {
//             openCount++;
//         } else {
//             openCount--;
//         }

//         // Invalid state
//         if (openCount < 0) {
//             return false;
//         }

//         // Destination
//         if (i == m - 1 && j == n - 1) {
//             return openCount == 0;
//         }

//         // Already calculated
//         if (dp[i][j][openCount] != -1) {
//             return dp[i][j][openCount];
//         }

//         bool down = memoizationSol(i + 1, j, openCount, grid, dp);

//         bool right = memoizationSol(i, j + 1, openCount, grid, dp);

//         return dp[i][j][openCount] = down || right;
//     }

//     int tabulationSol(vector<vector<char>>& grid,
//                       vector<vector<vector<int>>>& dp) {

//         int m = grid.size();
//         int n = grid[0].size();

//         // Recursion moves:
//         // (i, j) -> (i + 1, j)
//         // (i, j) -> (i, j + 1)
//         //
//         // Therefore, calculate from bottom-right
//         // towards top-left.

//         for (int i = m - 1; i >= 0; i--) {

//             for (int j = n - 1; j >= 0; j--) {

//                 for (int openCount = 0; openCount < m + n; openCount++) {

//                     int newOpenCount = openCount;

//                     // Process current cell
//                     if (grid[i][j] == '(') {
//                         newOpenCount++;
//                     } else {
//                         newOpenCount--;
//                     }

//                     // Invalid state
//                     if (newOpenCount < 0) {
//                         dp[i][j][openCount] = false;
//                         continue;
//                     }

//                     // Destination
//                     if (i == m - 1 && j == n - 1) {
//                         dp[i][j][openCount] = (newOpenCount == 0);
//                         continue;
//                     }

//                     bool down = false;
//                     bool right = false;

//                     if (i + 1 < m) {
//                         down = dp[i + 1][j][newOpenCount];
//                     }

//                     if (j + 1 < n) {
//                         right = dp[i][j + 1][newOpenCount];
//                     }

//                     dp[i][j][openCount] = down || right;
//                 }
//             }
//         }

//         return dp[0][0][0];
//     }

//     bool hasValidPath(vector<vector<char>>& grid) {

//         int m = grid.size();
//         int n = grid[0].size();

//         // Path length must be even
//         if ((m + n - 1) % 2 != 0) {
//             return false;
//         }

//         vector<vector<vector<int>>> dp2(
//             m, vector<vector<int>>(n, vector<int>(m + n + 1, -1)));

//         return tabulationSol(grid, dp2);

//         // // dp[i][j][openCount]
//         // vector<vector<vector<int>>> dp(
//         //     m, vector<vector<int>>(n, vector<int>(m + n + 1, -1)));

//         // return memoizationSol(0, 0, 0, grid, dp); // Works
//         // return recursionSol(0, 0, 0, grid); // TLE
//     }
// };