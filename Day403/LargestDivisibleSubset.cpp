// // 368. Largest Divisible Subset
// // Solved
// // Medium
// // Topics
// // premium lock icon
// // Companies
// // Given a set of distinct positive integers nums, return the largest subset
// // answer such that every pair (answer[i], answer[j]) of elements in this
// subset
// // satisfies:

// // answer[i] % answer[j] == 0, or
// // answer[j] % answer[i] == 0
// // If there are multiple solutions, return any of them.

// // Example 1:

// // Input: nums = [1,2,3]
// // Output: [1,2]
// // Explanation: [1,3] is also accepted.
// // Example 2:

// // Input: nums = [1,2,4,8]
// // Output: [1,2,4,8]

// // Constraints:

// // 1 <= nums.length <= 1000
// // 1 <= nums[i] <= 2 * 109
// // All the integers in nums are unique.

// class Solution {
// public:
//     vector<int> largestDivisibleSubset(vector<int>& nums) {
//         sort(nums.begin(), nums.end());
//         int n = nums.size();

//         if (n == 0) {
//             return {};
//         }

//         int maxi = 1;
//         int lastInd = 0;

//         vector<int> dp(n, 1), hash(n);

//         for (int i = 0; i < n; i++) {

//             hash[i] = i;

//             for (int prev = 0; prev < i; prev++) {

//                 if (nums[i] % nums[prev] == 0 && dp[i] < 1 + dp[prev]) {

//                     dp[i] = 1 + dp[prev];
//                     hash[i] = prev;
//                 }
//             }

//             if (dp[i] > maxi) {
//                 maxi = dp[i];
//                 lastInd = i;
//             }
//         }

//         vector<int> temp;

//         temp.push_back(nums[lastInd]);

//         while (hash[lastInd] != lastInd) {

//             lastInd = hash[lastInd];

//             temp.push_back(nums[lastInd]);
//         }

//         reverse(temp.begin(), temp.end());
//         return temp;
//     }
// };