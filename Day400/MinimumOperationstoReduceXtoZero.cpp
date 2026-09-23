// // 1658. Minimum Operations to Reduce X to Zero
// // Attempted
// // Medium
// // Topics
// // premium lock icon
// // Companies
// // Hint
// // You are given an integer array nums and an integer x. In one operation,
// you
// // can either remove the leftmost or the rightmost element from the array
// nums
// // and subtract its value from x. Note that this modifies the array for
// future
// // operations.

// // Return the minimum number of operations to reduce x to exactly 0 if it is
// // possible, otherwise, return -1.

// // Example 1:

// // Input: nums = [1,1,4,2,3], x = 5
// // Output: 2
// // Explanation: The optimal solution is to remove the last two elements to
// // reduce x to zero. Example 2:

// // Input: nums = [5,6,7,8,9], x = 4
// // Output: -1
// // Example 3:

// // Input: nums = [3,2,20,1,1,3], x = 10
// // Output: 5
// // Explanation: The optimal solution is to remove the last three elements and
// // the first two elements (5 operations in total) to reduce x to zero.

// // Constraints:

// // 1 <= nums.length <= 105
// // 1 <= nums[i] <= 104
// // 1 <= x <= 109

// class Solution {
// public:
//     int recursionSol(int left, int right, vector<int>& nums, int x) {
//         // X has been reduced to zero
//         if (x == 0) {
//             return 0;
//         }

//         // No elements left
//         if (left > right) {
//             return 1e9;
//         }

//         // Remove from left
//         int leftPicked =
//             1 + recursionSol(left + 1, right, nums, x - nums[left]);

//         // Remove from right
//         int rightPicked =
//             1 + recursionSol(left, right - 1, nums, x - nums[right]);

//         return min(leftPicked, rightPicked);
//     }
//     int memoizationSol(int left, int right, vector<int>& nums, int x,
//                        vector<vector<vector<int>>>& dp) {
//         // X has been reduced to zero
//         if (x == 0) {
//             return 0;
//         }
//         // X has gone below zero
//         if (x < 0) {
//             return 1e9;
//         }
//         // No elements left
//         if (left > right) {
//             return 1e9;
//         }
//         if (dp[left][right][x] != -1) {
//             return dp[left][right][x];
//         }

//         // Remove from left
//         int leftPicked =
//             1 + memoizationSol(left + 1, right, nums, x - nums[left], dp);

//         // Remove from right
//         int rightPicked =
//             1 + memoizationSol(left, right - 1, nums, x - nums[right], dp);

//         return dp[left][right][x] = min(leftPicked, rightPicked);
//     }

//     int tabulationSol(vector<int>& nums, int x,
//                       vector<vector<vector<int>>>& dp) {

//         int n = nums.size();
//         const int INF = 1e9;

//         // x = 0 means we need 0 operations
//         for (int left = 0; left < n; left++) {
//             for (int right = left; right < n; right++) {
//                 dp[left][right][0] = 0;
//             }
//         }

//         // left + 1 must already be calculated
//         // right - 1 must already be calculated
//         for (int left = n - 1; left >= 0; left--) {

//             for (int right = left; right < n; right++) {

//                 for (int remainingX = 1; remainingX <= x; remainingX++) {

//                     int leftPicked = INF;
//                     int rightPicked = INF;

//                     // Remove from left
//                     if (remainingX >= nums[left]) {

//                         if (left + 1 > right) {
//                             leftPicked = 1;
//                         } else {
//                             leftPicked =
//                                 1 +
//                                 dp[left + 1][right][remainingX - nums[left]];
//                         }
//                     }

//                     // Remove from right
//                     if (remainingX >= nums[right]) {

//                         if (left > right - 1) {
//                             rightPicked = 1;
//                         } else {
//                             rightPicked =
//                                 1 +
//                                 dp[left][right - 1][remainingX -
//                                 nums[right]];
//                         }
//                     }

//                     dp[left][right][remainingX] = min(leftPicked,
//                     rightPicked);
//                 }
//             }
//         }

//         return dp[0][n - 1][x];
//     }

//     int minOperations(vector<int>& nums, int x) {
//         // int ans = recursionSol(0, nums.size() - 1, nums, x); // TLE
//         int n = nums.size();
//         // vector<vector<vector<int>>> dp(
//         //     n, vector<vector<int>>(n, vector<int>(x + 1, -1)));
//         // int ans = memoizationSol(0, nums.size() - 1, nums, x, dp); // TLE
//         vector<vector<vector<int>>> dp(
//             n, vector<vector<int>>(n, vector<int>(x + 1, 0)));
//         int ans = tabulationSol(nums, x, dp);

//         if (ans >= 1e9) {
//             return -1;
//         }

//         return ans;
//     }
// };