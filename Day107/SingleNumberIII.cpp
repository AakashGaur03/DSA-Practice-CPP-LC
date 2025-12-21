// // Single Number III
// // Solved
// // Medium
// // Topics
// // premium lock icon
// // Companies
// // Given an integer array nums, in which exactly two elements appear only
// once
// // and all the other elements appear exactly twice. Find the two elements
// that
// // appear only once. You can return the answer in any order.

// // You must write an algorithm that runs in linear runtime complexity and
// uses
// // only constant extra space.

// // Example 1:

// // Input: nums = [1,2,1,3,2,5]
// // Output: [3,5]
// // Explanation:  [5, 3] is also a valid answer.
// // Example 2:

// // Input: nums = [-1,0]
// // Output: [-1,0]
// // Example 3:

// // Input: nums = [0,1]
// // Output: [1,0]

// // Constraints:

// // 2 <= nums.length <= 3 * 104
// // -231 <= nums[i] <= 231 - 1
// // Each integer in nums will appear twice, only two integers will appear
// once.

// class Solution {
// public:
//   vector<int> singleNumber(vector<int> &nums) {
//     // Step XOR of each number
//     long xorr = 0;
//     int n = nums.size();
//     for (int i = 0; i < n; i++) {
//       xorr ^= nums[i];
//     }
//     // Get rightmost set bit
//     long rightMost = xorr & (-xorr);

//     // Divide in two buckets
//     // as the numbers in each bucket will be odd
//     // because rightMost will help to divide both single number
//     // in different buckets

//     int b1 = 0;
//     int b2 = 0;

//     for (int i = 0; i < n; i++) {
//       // Check if rightMost Bit is set in that number or not
//       if (rightMost & nums[i]) {
//         b1 ^= nums[i];
//       } else {
//         b2 ^= nums[i];
//       }
//     }

//     return {b1, b2};
//   }
// };