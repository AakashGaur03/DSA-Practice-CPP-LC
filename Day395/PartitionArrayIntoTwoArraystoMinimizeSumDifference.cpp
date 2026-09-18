// // 2035. Partition Array Into Two Arrays to Minimize Sum Difference
// // Hard
// // Topics
// // premium lock icon
// // Companies
// // Hint
// // You are given an integer array nums of 2 * n integers. You need to
// partition
// // nums into two arrays of length n to minimize the absolute difference of
// the
// // sums of the arrays. To partition nums, put each element of nums into one
// of
// // the two arrays.

// // Return the minimum possible absolute difference.

// // Example 1:

// // example-1
// // Input: nums = [3,9,7,3]
// // Output: 2
// // Explanation: One optimal partition is: [3,9] and [7,3].
// // The absolute difference between the sums of the arrays is abs((3 + 9) - (7
// +
// // 3)) = 2. Example 2:

// // Input: nums = [-36,36]
// // Output: 72
// // Explanation: One optimal partition is: [-36] and [36].
// // The absolute difference between the sums of the arrays is abs((-36) -
// (36))
// // = 72. Example 3:

// // example-3
// // Input: nums = [2,-1,0,4,-2,-9]
// // Output: 0
// // Explanation: One optimal partition is: [2,4,-9] and [-1,0,-2].
// // The absolute difference between the sums of the arrays is abs((2 + 4 + -9)
// -
// // (-1 + 0 + -2)) = 0.

// // Constraints:

// // 1 <= n <= 15
// // nums.length == 2 * n
// // -107 <= nums[i] <= 107

// class Solution {
// public:
//     bool subsetSumtoK(int n, int k, vector<int>& arr,
//                       vector<vector<bool>>& dp) {
//         for (int i = 0; i < n; i++) {
//             dp[i][0] = true;
//         }
//         if (arr[0] <= k && arr[0] >= 0) {
//             dp[0][arr[0]] = true;
//         }

//         for (int ind = 1; ind < n; ind++) {
//             for (int target = 1; target <= k; target++) {
//                 bool notTake = dp[ind - 1][target];
//                 bool take = false;
//                 if (arr[ind] <= target) {
//                     take = dp[ind - 1][target - arr[ind]];
//                 }
//                 dp[ind][target] = take | notTake;
//             }
//         }
//         return dp[n - 1][k];
//     }

//     int minimumDifference(vector<int>& nums) {
//         int n = nums.size();
//         int totSum = 0;
//         for (int i = 0; i < n; i++) {
//             totSum += nums[i];
//         }
//         vector<vector<bool>> dp(n, vector<bool>(totSum + 1, false));

//         subsetSumtoK(n, totSum, nums, dp);

//         int mini = 1e9;
//         // If s1 > totalSum / 2,
//         // then s2 < totalSum / 2.
//         //
//         // That partition is already represented when we
//         // consider s2 instead of s1.
//         //
//         // Therefore, checking both sides would be redundant.
//         //
//         // Also, the closer s1 is to totalSum / 2,
//         // the smaller the difference will be.

//         for (int s1 = 0; s1 < totSum / 2; s1++) {
//             if (dp[n - 1][s1] == true) {
//                 mini = min(mini, abs((totSum - s1) - s1));
//             }
//         }

//         return mini;
//     }
// };

// Line 31: Char 30:
// =================================================================
// ==22==ERROR: AddressSanitizer: heap-buffer-overflow on address 0x5020000002c8
// at pc 0x55e3432cade9 bp 0x7fff73d3def0 sp 0x7fff73d3dee8 READ of size 8 at
// 0x5020000002c8 thread T0
//     #0 0x55e3432cade8 in std::_Bit_iterator std::__copy_move<false, false,
//     std::random_access_iterator_tag>::__copy_m<std::_Bit_const_iterator,
//     std::_Bit_iterator>(std::_Bit_const_iterator, std::_Bit_const_iterator,
//     std::_Bit_iterator) (solution+0x1a6de8) #1 0x55e3432afc7a in
//     __copy_move_a2<false, std::_Bit_const_iterator, std::_Bit_iterator>
//     /usr/lib/gcc/x86_64-linux-gnu/14/../../../../include/c++/14/bits/stl_algobase.h:520:14
//     #2 0x55e3432afc7a in __copy_move_a1<false, std::_Bit_const_iterator,
//     std::_Bit_iterator>
//     /usr/lib/gcc/x86_64-linux-gnu/14/../../../../include/c++/14/bits/stl_algobase.h:548:14