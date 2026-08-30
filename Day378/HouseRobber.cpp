// // 198. House Robber
// // Solved
// // Medium
// // Topics
// // premium lock icon
// // Companies
// // You are a professional robber planning to rob houses along a street. Each
// // house has a certain amount of money stashed, the only constraint stopping
// you
// // from robbing each of them is that adjacent houses have security systems
// // connected and it will automatically contact the police if two adjacent
// houses
// // were broken into on the same night.

// // Given an integer array nums representing the amount of money of each
// house,
// // return the maximum amount of money you can rob tonight without alerting
// the
// // police.

// // Example 1:

// // Input: nums = [1,2,3,1]
// // Output: 4
// // Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
// // Total amount you can rob = 1 + 3 = 4.
// // Example 2:

// // Input: nums = [2,7,9,3,1]
// // Output: 12
// // Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob
// house 5
// // (money = 1). Total amount you can rob = 2 + 9 + 1 = 12.

// // Constraints:

// // 1 <= nums.length <= 100
// // 0 <= nums[i] <= 400

// class Solution {
// public:
//     int recursionSol(int ind, vector<int>& nums) {
//         if (ind == 0) {
//             return nums[ind];
//         }
//         if (ind < 0) {
//             return 0;
//         }

//         int pick = nums[ind] + recursionSol(ind - 2, nums);
//         int notPick = 0 + recursionSol(ind - 1, nums);

//         return max(pick, notPick);
//     }
//     int memoizationSol(int ind, vector<int>& nums, vector<int>& dp) {
//         if (ind == 0) {
//             return nums[ind];
//         }
//         if (ind < 0) {
//             return 0;
//         }
//         if (dp[ind] != -1) {
//             return dp[ind];
//         }

//         int pick = nums[ind] + memoizationSol(ind - 2, nums, dp);

//         int notPick = memoizationSol(ind - 1, nums, dp);

//         return dp[ind] = max(pick, notPick);
//     }

//     int tabulationSol(int ind, vector<int>& nums, vector<int>& dp) {
//         dp[0] = nums[0];

//         for (int i = 1; i < nums.size(); i++) {

//             int pick = nums[i];
//             if (i > 1) {
//                 pick += dp[i - 2];
//             }
//             int notPick = dp[i - 1];
//             dp[i] = max(pick, notPick);
//         }

//         return dp[ind];
//     }
//     int spaceOptimizedSol(int ind, vector<int>& nums) {
//         int prev = nums[0];
//         int prev2 = 0;

//         for (int i = 1; i < nums.size(); i++) {

//             int pick = nums[i];
//             if (i > 1) {
//                 pick += prev2;
//             }
//             int notPick = prev;
//             int curr = max(pick, notPick);
//             prev2 = prev;
//             prev = curr;

//         }

//         return prev;
//     }
//     int rob(vector<int>& nums) {
//         int n = nums.size();
//         // return recursionSol(n - 1, nums); // TLE
//         // vector<int> dp(n, -1);
//         // return memoizationSol(n - 1, nums, dp); // Accepted
//         // vector<int> dp(n, 0);
//         // return tabulationSol(n - 1, nums, dp); // Accepted

//         return spaceOptimizedSol(n - 1, nums); // Accepted
//     }
// };