// // 120. Triangle
// // Solved
// // Medium
// // Topics
// // premium lock icon
// // Companies
// // Given a triangle array, return the minimum path sum from top to bottom.

// // For each step, you may move to an adjacent number of the row below. More
// // formally, if you are on index i on the current row, you may move to either
// // index i or index i + 1 on the next row.

// // Example 1:

// // Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
// // Output: 11
// // Explanation: The triangle looks like:
// //    2
// //   3 4
// //  6 5 7
// // 4 1 8 3
// // The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined
// // above). Example 2:

// // Input: triangle = [[-10]]
// // Output: -10

// // Constraints:

// // 1 <= triangle.length <= 200
// // triangle[0].length == 1
// // triangle[i].length == triangle[i - 1].length + 1
// // -104 <= triangle[i][j] <= 104

// // Follow up: Could you do this using only O(n) extra space, where n is the
// // total number of rows in the triangle?

// class Solution {
// public:
//     int recursionSol(int i, int j, int n, vector<vector<int>>& triangle) {
//         if (i == n - 1) {
//             return triangle[i][j];
//         }
//         int down = triangle[i][j] + recursionSol(i + 1, j, n, triangle);
//         int right = triangle[i][j] + recursionSol(i + 1, j + 1, n, triangle);

//         return min(down, right);
//     }

//     int memoizationSol(int i, int j, int n, vector<vector<int>>& triangle,
//                        vector<vector<int>>& dp) {
//         if (i == n - 1) {
//             return dp[i][j] = triangle[i][j];
//         }
//         if (dp[i][j] != -1) {
//             return dp[i][j];
//         }
//         int down = triangle[i][j] + memoizationSol(i + 1, j, n, triangle,
//         dp); int right =
//             triangle[i][j] + memoizationSol(i + 1, j + 1, n, triangle, dp);

//         return dp[i][j] = min(down, right);
//     }

//     int tabulationSol(int n, vector<vector<int>>& triangle,
//                       vector<vector<int>>& dp) {

//         for (int j = 0; j < n; j++) {
//             dp[n - 1][j] = triangle[n - 1][j];
//         }

//         for (int i = n - 2; i >= 0; i--) {
//             for (int j = i; j >= 0; j--) {
//                 int down = triangle[i][j] + dp[i + 1][j];
//                 int right = triangle[i][j] + dp[i + 1][j + 1];
//                 dp[i][j] = min(down, right);
//             }
//         }
//         return dp[0][0];
//     }
//     int spaceOptimizationSol(int n, vector<vector<int>>& triangle) {
//         vector<int> front(n, 0);
//         vector<int> curr(n, 0);

//         for (int j = 0; j < n; j++) {
//             front[j] = triangle[n - 1][j];
//         }

//         for (int i = n - 2; i >= 0; i--) {
//             for (int j = i; j >= 0; j--) {
//                 int down = triangle[i][j] + front[j];
//                 int right = triangle[i][j] + front[j + 1];
//                 curr[j] = min(down, right);
//             }
//             front = curr;
//         }
//         return front[0];
//     }

//     int minimumTotal(vector<vector<int>>& triangle) {
//         int n = triangle.size();
//         // return recursionSol(0, 0, n, triangle); // TLE
//         // vector<vector<int>> dp(n, vector<int>(n, -1));
//         // return memoizationSol(0, 0, n, triangle, dp); // TLE
//         // vector<vector<int>> dp(n, vector<int>(n, 0));
//         // return tabulationSol(n, triangle, dp); // Works
//         return spaceOptimizationSol(n, triangle); // Works
//     }
// };