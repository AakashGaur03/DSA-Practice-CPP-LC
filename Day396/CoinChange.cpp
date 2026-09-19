// // 322. Coin Change
// // Solved
// // Medium
// // Topics
// // premium lock icon
// // Companies
// // You are given an integer array coins representing coins of different
// // denominations and an integer amount representing a total amount of money.

// // Return the fewest number of coins that you need to make up that amount. If
// // that amount of money cannot be made up by any combination of the coins,
// // return -1.

// // You may assume that you have an infinite number of each kind of coin.

// // Example 1:

// // Input: coins = [1,2,5], amount = 11
// // Output: 3
// // Explanation: 11 = 5 + 5 + 1
// // Example 2:

// // Input: coins = [2], amount = 3
// // Output: -1
// // Example 3:

// // Input: coins = [1], amount = 0
// // Output: 0

// // Constraints:

// // 1 <= coins.length <= 12
// // 1 <= coins[i] <= 231 - 1
// // 0 <= amount <= 104

// class Solution {
// public:
//     int memoizationSol(int n, vector<int>& coins, int amount,
//                        vector<vector<int>>& dp) {

//         // Base case
//         if (n == 0) {
//             if (amount % coins[0] == 0) {
//                 return amount / coins[0];
//             }

//             return 1e7;
//         }

//         if (dp[n][amount] != -1) {
//             return dp[n][amount];
//         }

//         // Don't pick current coin
//         int notPick = memoizationSol(n - 1, coins, amount, dp);

//         // Pick current coin
//         int pick = 1e7;

//         if (coins[n] <= amount) {
//             pick = 1 + memoizationSol(n, coins, amount - coins[n], dp);
//         }

//         return dp[n][amount] = min(pick, notPick);
//     }
//     int tabulationSol(int size, vector<int>& coins, int target,
//                       vector<vector<int>>& dp) {

//         for (int amount = 0; amount <= target; amount++) {
//             if (amount % coins[0] == 0) {
//                 dp[0][amount] = amount / coins[0];
//             } else {
//                 dp[0][amount] = 1e7;
//             }
//         }

//         for (int n = 1; n <= size; n++) {
//             for (int amount = 0; amount <= target; amount++) {

//                 // Don't pick current coin
//                 int notPick = dp[n - 1][amount];

//                 // Pick current coin
//                 int pick = 1e7;

//                 if (coins[n] <= amount) {
//                     pick = 1 + dp[n][amount - coins[n]];
//                 }

//                 dp[n][amount] = min(pick, notPick);
//             }
//         }
//         return dp[size][target];
//     }
//     int spaceOptimizedSol(int size, vector<int>& coins, int target) {

//         vector<int> prev(target + 1, 0);
//         vector<int> curr(target + 1, 0);

//         for (int amount = 0; amount <= target; amount++) {
//             if (amount % coins[0] == 0) {
//                 prev[amount] = amount / coins[0];
//             } else {
//                 prev[amount] = 1e7;
//             }
//         }

//         for (int n = 1; n <= size; n++) {
//             for (int amount = 0; amount <= target; amount++) {

//                 // Don't pick current coin
//                 int notPick = prev[amount];

//                 // Pick current coin
//                 int pick = 1e7;

//                 if (coins[n] <= amount) {
//                     pick = 1 + curr[amount - coins[n]];
//                 }

//                 curr[amount] = min(pick, notPick);
//             }
//             prev = curr;
//         }
//         return prev[target];
//     }

//     int coinChange(vector<int>& coins, int amount) {

//         int n = coins.size();
//         vector<vector<int>> dp(n, vector<int>(amount + 1, 0));

//         int ans = spaceOptimizedSol(n - 1, coins, amount);

//         if (ans >= 1e7) {
//             return -1;
//         }

//         return ans;
//         // int n = coins.size();
//         // vector<vector<int>> dp(n, vector<int>(amount + 1, 0));

//         // int ans = tabulationSol(n - 1, coins, amount, dp);

//         // if (ans >= 1e7) {
//         //     return -1;
//         // }

//         // return ans;
//         // int n = coins.size();
//         // vector<vector<int>> dp(n, vector<int>(amount + 1, -1));

//         // int ans = memoizationSol(n - 1, coins, amount, dp);

//         // if (ans >= 1e7) {
//         //     return -1;
//         // }

//         // return ans;
//     }
// };