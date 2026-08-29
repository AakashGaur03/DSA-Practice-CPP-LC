// //  Climbing Stairs
// // Solved
// // Easy
// // Topics
// // premium lock icon
// // Companies
// // Hint
// // You are climbing a staircase. It takes n steps to reach the top.

// // Each time you can either climb 1 or 2 steps. In how many distinct ways can
// // you climb to the top?

// // Example 1:

// // Input: n = 2
// // Output: 2
// // Explanation: There are two ways to climb to the top.
// // 1. 1 step + 1 step
// // 2. 2 steps
// // Example 2:

// // Input: n = 3
// // Output: 3
// // Explanation: There are three ways to climb to the top.
// // 1. 1 step + 1 step + 1 step
// // 2. 1 step + 2 steps
// // 3. 2 steps + 1 step
// class Solution {
// public:
//     int solveSpaceOptimized(int n) {
//         if (n <= 2) {
//             return n;
//         }

//         int prev = 1;
//         int prev2 = 2;

//         for (int i = 3; i <= n; i++) {
//             int curr = prev + prev2;
//             prev = prev2;
//             prev2 = curr;
//         }
//         return prev2;
//     }
//     int climbStairs(int n) {
//         // Memoization
//         // vector<int> dp(n + 1, -1);
//         // return solve(n, dp);
//         // Tabulation
//         vector<int> dp(n + 1, 0);
//         return solveSpaceOptimized(n);
//     }
// };

// // // Recursion
// // int climbStairs(int n) {
// //     if (n <= 2) {
// //         return n;
// //     }

// //     return climbStairs(n - 1) + climbStairs(n - 2);
// // }

// // // Memoization
// // int solve(int n, vector<int>& dp) {
// //     if (n <= 2) {
// //         return n;
// //     }
// //     if (dp[n] != -1) {
// //         return dp[n];
// //     }
// //     return dp[n] = solve(n - 1, dp) + solve(n - 2, dp);
// // }

// // // Tabulation
// // int solveTabulation(int n, vector<int>& dp) {
// //     if (n <= 2) {
// //         return n;
// //     }
// //     dp[1] = 1;
// //     dp[2] = 2;

// //     for (int i = 3; i <= n; i++) {
// //         dp[i] = dp[i - 1] + dp[i - 2];
// //     }
// //     return dp[n];
// // }