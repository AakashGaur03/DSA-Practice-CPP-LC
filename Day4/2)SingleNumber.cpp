// 136. Single Number
// Solved
// Easy
// Topics
// premium lock icon
// Companies
// Hint
// Given a non-empty array of integers nums, every element appears twice except
// for one. Find that single one.

// You must implement a solution with a linear runtime complexity and use only
// constant extra space.

// Example 1:

// Input: nums = [2,2,1]

// Output: 1

// Example 2:

// Input: nums = [4,1,2,1,2]

// Output: 4

// Example 3:

// Input: nums = [1]

// Output: 1

// class Solution {
// public:
//     int singleNumber(vector<int>& nums) {
//         // TC O(N) By XOR
//         int res = 0;
//         for(int i = 0; i<nums.size();i++){
//             res ^= nums[i];
//         }

//         return res;
//     }
// };
// // // TC O(N log N + Log N) By Sorting + Binary Search (For Practice)
// // // If Input is sorted so most Optimal Binary Search
// //   int singleNumberBinarySearch(vector<int>& nums) {
// //         sort(nums.begin(), nums.end()); // sort first

// //         int n = nums.size();
// //         // Handle edge cases
// //         if (n == 1) return nums[0]; // only one element
// //         if (nums[0] != nums[1]) return nums[0]; // unique at start
// //         if (nums[n - 1] != nums[n - 2]) return nums[n - 1]; // unique at
// end

// //         int low = 1, high = n - 2; // search in the middle (edges already
// checked)

// //         while (low <= high) {
// //             int mid = low + (high - low) / 2;

// //             if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1])
// {
// //                 return nums[mid];
// //             }

// //             // if nums[mid] is at even index and same value at right then
// answer in right side and if at odd and at left side
// //             if ((mid % 2 == 0 && nums[mid] == nums[mid + 1]) ||
// //                 (mid % 2 == 1 && nums[mid] == nums[mid - 1])) {
// //                 low = mid + 1;
// //             } else {
// //                 high = mid - 1; // left side
// //             }
// //         }
// //         return -1; // should not reach here
// //     }