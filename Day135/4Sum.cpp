// // 4Sum
// // Solved
// // Medium
// // Topics
// // premium lock icon
// // Companies
// // Given an array nums of n integers, return an array of all the unique
// // quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

// // 0 <= a, b, c, d < n
// // a, b, c, and d are distinct.
// // nums[a] + nums[b] + nums[c] + nums[d] == target
// // You may return the answer in any order.

// // Example 1:

// // Input: nums = [1,0,-1,0,-2,2], target = 0
// // Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
// // Example 2:

// // Input: nums = [2,2,2,2,2], target = 8
// // Output: [[2,2,2,2]]

// // Constraints:

// // 1 <= nums.length <= 200
// // -109 <= nums[i] <= 109
// // -109 <= target <= 109

// class Solution {
// public:
//     vector<vector<int>> fourSum(vector<int>& nums, int target) {
//         int size = nums.size();

//         vector<vector<int>> ans;

//         sort(nums.begin(), nums.end());

//         for (int i = 0; i < size; i++) {
//             // Skip duplicate values for the first pointer
//             if (i > 0 && nums[i] == nums[i - 1]) {
//                 continue;
//             }
//             for (int j = i + 1; j < size; j++) {
//                 // Skip duplicate values for the second pointer
//                 if (j != i + 1 && nums[j] == nums[j - 1]) {
//                     continue;
//                 }
//                 int k = j + 1;
//                 int l = size - 1;
//                 while (k < l) {
//                     // Use long long to avoid integer overflow
//                     long long sum = nums[i];
//                     sum += nums[j];
//                     sum += nums[k];
//                     sum += nums[l];
//                     if (sum == target) {
//                         vector<int> temp = {nums[i], nums[j], nums[k],
//                         nums[l]}; ans.push_back(temp); k++; l--;
//                         // Skip duplicate values for third pointer
//                         while (k < l && nums[k] == nums[k - 1]) {
//                             k++;
//                         }
//                         // Skip duplicate values for fourth pointer
//                         while (k < l && nums[l] == nums[l + 1]) {
//                             l--;
//                         }
//                     } else if (sum < target) {
//                         k++;
//                     } else {
//                         l--;
//                     }
//                 }
//             }
//         }

//         return ans;
//     }
// };

// // BRUTE
// // vector<vector<int>> fourSum(vector<int>& nums, int target) {
// //     set<vector<int>> st;
// //     int size = nums.size();

// //     for (int i = 0; i < size; i++) {
// //         for (int j = i + 1; j < size; j++) {
// //             for (int k = j + 1; k < size; k++) {
// //                 for (int l = k + 1; l < size; l++) {
// //                     if ((long long)nums[i] + nums[j] + nums[k] + nums[l]
// ==
// //                         target) {
// //                         vector<int> temp = {nums[i], nums[j], nums[k],
// //                         nums[l]}; sort(temp.begin(), temp.end());
// //                         st.insert(temp);
// //                     }
// //                 }
// //             }
// //         }
// //     }

// //     vector<vector<int>> ans(st.begin(), st.end());

// //     return ans;
// // }

// // Better Solution
// // vector<vector<int>> fourSum(vector<int>& nums, int target) {
// //     int size = nums.size();
// //     set<vector<int>> st;

// //     for (int i = 0; i < size; i++) {
// //         for (int j = i + 1; j < size; j++) {
// //             set<long long> hashSet;
// //             for (int k = j + 1; k < size; k++) {
// //                 long long sum3 = (long long)nums[i] + nums[j] + nums[k];

// //                 long long fourth = target - sum3;
// //                 if (hashSet.find(fourth) != hashSet.end()) {
// //                     vector<int> temp = {nums[i], nums[j], nums[k],
// //                     (int)fourth}; sort(temp.begin(), temp.end());
// //                     st.insert(temp);
// //                 }
// //                 hashSet.insert(nums[k]);
// //             }
// //         }
// //     }

// //     vector<vector<int>> ans(st.begin(), st.end());
// //     return ans;
// // }