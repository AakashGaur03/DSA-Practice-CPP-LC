// // 416. Partition Equal Subset Sum
// // Solved
// // Medium
// // Topics
// // premium lock icon
// // Companies
// // Given an integer array nums, return true if you can partition the array
// into
// // two subsets such that the sum of the elements in both subsets is equal or
// // false otherwise.

// // Example 1:

// // Input: nums = [1,5,11,5]
// // Output: true
// // Explanation: The array can be partitioned as [1, 5, 5] and [11].
// // Example 2:

// // Input: nums = [1,2,3,5]
// // Output: false
// // Explanation: The array cannot be partitioned into equal sum subsets.

// // Constraints:

// // 1 <= nums.length <= 200
// // 1 <= nums[i] <= 100

// class Solution {
// public:
//     bool recursionSol(int ind, vector<int>& nums, int target) {
//         if (target == 0) {
//             return true;
//         }
//         if (ind == 0) {
//             return (nums[0] == target);
//         }
//         bool notTake = recursionSol(ind - 1, nums, target);
//         bool take = false;
//         if (nums[ind] <= target) {
//             take = recursionSol(ind - 1, nums, target - nums[ind]);
//         }
//         return take | notTake;
//     }

//     bool memoizationSol(int ind, vector<int>& nums, int target,
//                         vector<vector<int>>& dp) {
//         if (target == 0) {
//             return true;
//         }
//         if (ind == 0) {
//             return (nums[0] == target);
//         }
//         if (dp[ind][target] != -1) {
//             return dp[ind][target];
//         }
//         bool notTake = memoizationSol(ind - 1, nums, target, dp);
//         bool take = false;
//         if (nums[ind] <= target) {
//             take = memoizationSol(ind - 1, nums, target - nums[ind], dp);
//         }
//         return dp[ind][target] = take | notTake;
//     }

//     bool tabulationSol(int n, vector<int>& nums, int k,
//                        vector<vector<bool>>& dp) {

//         for (int i = 0; i < n; i++) {
//             dp[i][0] = true;
//         }
//         if (nums[0] <= k) {
//             dp[0][nums[0]] = true;
//         }

//         for (int ind = 1; ind < n; ind++) {
//             for (int target = 1; target <= k; target++) {
//                 bool notTake = dp[ind - 1][target];
//                 bool take = false;
//                 if (nums[ind] <= target) {
//                     take = dp[ind - 1][target - nums[ind]];
//                 }
//                 dp[ind][target] = take | notTake;
//             }
//         }
//         return dp[n - 1][k];
//     }
//     bool spaceOptimizationSol(int n, vector<int>& nums, int k) {
//         vector<bool> prev(k + 1, 0);
//         vector<bool> curr(k + 1, 0);
//         prev[0] = curr[0] = true;

//         if (nums[0] <= k) {

//             prev[nums[0]] = true;
//         }

//         for (int ind = 1; ind < n; ind++) {
//             for (int target = 1; target <= k; target++) {
//                 bool notTake = prev[target];
//                 bool take = false;
//                 if (nums[ind] <= target) {
//                     take = prev[target - nums[ind]];
//                 }
//                 curr[target] = take | notTake;
//             }
//             prev = curr;
//         }
//         return prev[k];
//     }

//     bool canPartition(vector<int>& nums) {
//         int sum = 0;
//         int n = nums.size();
//         for (int i = 0; i < n; i++) {
//             sum += nums[i];
//         }
//         // If odd then False
//         if (sum % 2 != 0)
//             return false;

//         // if even then check sum/2
//         sum = sum / 2;
//         // return recursionSol(n - 1, nums, sum); // TLE
//         // vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
//         // return memoizationSol(n - 1, nums, sum, dp); // Works
//         // vector<vector<bool>> dp(n, vector<bool>(sum + 1, false));
//         // return tabulationSol(n, nums, sum, dp); // Works
//         return spaceOptimizationSol(n, nums, sum);
//     }
// };