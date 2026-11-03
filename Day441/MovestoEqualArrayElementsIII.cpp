// // Minimum Moves to Equal Array Elements III
// // Solved
// // Easy
// // Topics
// // premium lock icon
// // Companies
// // Hint
// // You are given an integer array nums.

// // In one move, you may increase the value of any single element nums[i]
// by 1.

// // Return the minimum total number of moves required so that all elements in
// // nums become equal.

// // Example 1:

// // Input: nums = [2,1,3]

// // Output: 3

// // Explanation:

// // To make all elements equal:

// // Increase nums[0] = 2 by 1 to make it 3.
// // Increase nums[1] = 1 by 1 to make it 2.
// // Increase nums[1] = 2 by 1 to make it 3.
// // Now, all elements of nums are equal to 3. The minimum total moves is 3.

// // Example 2:

// // Input: nums = [4,4,5]

// // Output: 2

// // Explanation:

// // To make all elements equal:

// // Increase nums[0] = 4 by 1 to make it 5.
// // Increase nums[1] = 4 by 1 to make it 5.
// // Now, all elements of nums are equal to 5. The minimum total moves is 2.

// // Constraints:

// // 1 <= nums.length <= 100
// // 1 <= nums[i] <= 100

// class Solution {
// public:
//     int minMoves(vector<int>& nums) {
//         int n = nums.size();
//         int currMax = nums[0];
//         int ans = 0;
//         // Single iteration
//         for (int i = 1; i < n; i++) {
//             if (nums[i] < currMax) {
//                 ans += currMax - nums[i];
//             } else {
//                 ans += (nums[i] - currMax) * i;
//                 currMax = nums[i];
//             }
//         }
//         return ans;
//     }
// };

// // int minMoves(vector<int>& nums) {
// //     int n = nums.size();
// //     int currMax = 0;
// //     int ans = 0;
// //     for (int i = 0; i < n; i++) {
// //         currMax = max(nums[i], currMax);
// //     }

// //     for (int i = 0; i < n; i++) {
// //         ans += currMax - nums[i];
// //     }
// //     return ans;
// // }