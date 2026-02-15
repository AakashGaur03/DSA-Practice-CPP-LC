// // Subarrays with K Different Integers
// // Solved
// // Hard
// // Topics
// // premium lock icon
// // Companies
// // Hint
// // Given an integer array nums and an integer k, return the number of good
// // subarrays of nums.

// // A good array is an array where the number of different integers in that
// array
// // is exactly k.

// // For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.
// // A subarray is a contiguous part of an array.

// // Example 1:

// // Input: nums = [1,2,1,2,3], k = 2
// // Output: 7
// // Explanation: Subarrays formed with exactly 2 different integers: [1,2],
// // [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2] Example 2:

// // Input: nums = [1,2,1,3,4], k = 3
// // Output: 3
// // Explanation: Subarrays formed with exactly 3 different integers:
// [1,2,1,3],
// // [2,1,3], [1,3,4].

// class Solution {
// public:
//   int subarraysWithLessThanOrEqualKDistinct(vector<int> &nums, int k) {
//     if (k < 0)
//       return 0;
//     int left = 0;
//     int right = 0;
//     int size = nums.size();
//     int cnt = 0;
//     int sum = 0;
//     unordered_map<int, int> mpp;
//     while (right < size) {
//       mpp[nums[right]]++;
//       while (mpp.size() > k) {
//         mpp[nums[left]]--;
//         if (mpp[nums[left]] == 0) {
//           mpp.erase(nums[left]);
//         }
//         left++;
//       }
//       cnt = cnt + (right - left + 1);
//       right++;
//     }
//     return cnt;
//   }
//   int subarraysWithKDistinct(vector<int> &nums, int k) {
//     return subarraysWithLessThanOrEqualKDistinct(nums, k) -
//            subarraysWithLessThanOrEqualKDistinct(nums, k - 1);
//   }
// };