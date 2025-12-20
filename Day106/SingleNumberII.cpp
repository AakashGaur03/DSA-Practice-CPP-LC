// // Single Number II
// // Solved
// // Medium
// // Topics
// // premium lock icon
// // Companies
// // Given an integer array nums where every element appears three times except
// // for one, which appears exactly once. Find the single element and return
// it.

// // You must implement a solution with a linear runtime complexity and use
// only
// // constant extra space.

// // Example 1:

// // Input: nums = [2,2,3,2]
// // Output: 3
// // Example 2:

// // Input: nums = [0,1,0,1,0,1,99]
// // Output: 99

// // Constraints:

// // 1 <= nums.length <= 3 * 104
// // -231 <= nums[i] <= 231 - 1
// // Each element in nums appears exactly three times except for one element
// which
// // appears once.

// class Solution {
// public:
//     int singleNumber(vector<int>& nums) {
//         // Bucket Appraoch

//         int ones = 0;
//         int twos = 0;

//         for (int i = 0; i < nums.size(); i++) {
//             // nums[i] will go to ones, if not in twos
//             // nums[i] will go to twos, if it is in ones
//             ones = (ones ^ nums[i]) & ~twos;
//             twos = (twos ^ nums[i]) & ~ones;
//         }
//         return ones;
//     }
// };

// // int singleNumber(vector<int>& nums) {
// //     int ans = 0;
// //     for (int bitIndex = 0; bitIndex < 32; bitIndex++) {
// //         int cnt = 0;
// //         for (int j = 0; j < nums.size(); j++) {
// //             // count setBits
// //             if (nums[j] & (1 << bitIndex)) {
// //                 cnt++;
// //             }
// //         }

// //         if (cnt % 3 == 1) {
// //             ans = ans | (1 << bitIndex);
// //         }
// //     }
// //     return ans;
// // }

// // // int singleNumber(vector<int>& nums) {
// // //     sort(nums.begin(), nums.end());

// //     for (int i = 1; i < nums.size(); i = i + 3) {
// //         if (nums[i] != nums[i - 1]) {
// //             return nums[i - 1];
// //         }
// //     }
// //     return nums[nums.size() - 1];
// // }