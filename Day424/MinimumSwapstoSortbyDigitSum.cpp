// // 3551. Minimum Swaps to Sort by Digit Sum
// // Solved
// // Medium
// // Topics
// // premium lock icon
// // Companies
// // Hint
// // You are given an array nums of distinct positive integers. You need to
// sort
// // the array in increasing order based on the sum of the digits of each
// number.
// // If two numbers have the same digit sum, the smaller number appears first
// in
// // the sorted order.

// // Return the minimum number of swaps required to rearrange nums into this
// // sorted order.

// // A swap is defined as exchanging the values at two distinct positions in
// the
// // array.

// // Example 1:

// // Input: nums = [37,100]

// // Output: 1

// // Explanation:

// // Compute the digit sum for each integer: [3 + 7 = 10, 1 + 0 + 0 = 1] → [10,
// 1]
// // Sort the integers based on digit sum: [100, 37]. Swap 37 with 100 to
// obtain
// // the sorted order. Thus, the minimum number of swaps required to rearrange
// // nums is 1. Example 2:

// // Input: nums = [22,14,33,7]

// // Output: 0

// // Explanation:

// // Compute the digit sum for each integer: [2 + 2 = 4, 1 + 4 = 5, 3 + 3 = 6,
// 7 =
// // 7] → [4, 5, 6, 7] Sort the integers based on digit sum: [22, 14, 33, 7].
// The
// // array is already sorted. Thus, the minimum number of swaps required to
// // rearrange nums is 0. Example 3:

// // Input: nums = [18,43,34,16]

// // Output: 2

// // Explanation:

// // Compute the digit sum for each integer: [1 + 8 = 9, 4 + 3 = 7, 3 + 4 = 7,
// 1 +
// // 6 = 7] → [9, 7, 7, 7] Sort the integers based on digit sum: [16, 34, 43,
// 18].
// // Swap 18 with 16, and swap 43 with 34 to obtain the sorted order. Thus, the
// // minimum number of swaps required to rearrange nums is 2.

// // Constraints:

// // 1 <= nums.length <= 105
// // 1 <= nums[i] <= 109
// // nums consists of distinct positive integers.

// class Solution {
// public:
//     static int digSum(int num) {
//         int sum = 0;
//         while (num > 0) {
//             sum += num % 10;
//             num /= 10;
//         }
//         return sum;
//     }
//     static bool comp(int num1, int num2) {
//         int num1DigSum = digSum(num1);
//         int num2DigSum = digSum(num2);

//         if (num1DigSum != num2DigSum) {
//             return num1DigSum < num2DigSum;
//         }
//         return num1 < num2;
//     }
//     int minSwaps(vector<int>& nums) {
//         // TC: O(n log n) average
//         // SC: O(n)

//         int n = nums.size();
//         vector<int> afterSorting(nums);

//         sort(begin(afterSorting), end(afterSorting), comp);

//         // Store the current index of each value.
//         unordered_map<int, int> valToIndex;
//         for (int i = 0; i < n; i++) {
//             valToIndex[nums[i]] = i;
//         }

//         int swapCnt = 0;

//         for (int i = 0; i < n; i++) {
//             int expectedVal = afterSorting[i];
//             int currVal = nums[i];

//             // Skip if the element is already in its correct position.
//             if (expectedVal == currVal) {
//                 continue;
//             }

//             // Find the current position of the element we need.
//             int idx = valToIndex[expectedVal];

//             // Place the expected element at index i.
//             nums[i] = expectedVal;
//             nums[idx] = currVal;

//             // Update both elements' positions in the map.
//             valToIndex[expectedVal] = i;
//             valToIndex[currVal] = idx;

//             swapCnt++;
//         }

//         return swapCnt;
//     }
// };