// // Subsets II
// // Solved
// // Medium
// // Topics
// // premium lock icon
// // Companies
// // Given an integer array nums that may contain duplicates, return all
// possible subsets (the power set).

// // The solution set must not contain duplicate subsets. Return the solution
// in any order.

// // Example 1:

// // Input: nums = [1,2,2]
// // Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
// // Example 2:

// // Input: nums = [0]
// // Output: [[],[0]]

//  class Solution {
// public:
//     void findSubsets(int index, vector<int>& nums, vector<int>& ds,
//                      vector<vector<int>>& ans) {
//         int n = nums.size();
//             ans.push_back(ds);

//         for (int i = index; i < n; i++) {
//             if(i>index && nums[i]==nums[i-1]) continue;
//             ds.push_back(nums[i]);
//             findSubsets(i+1, nums, ds, ans);
//             ds.pop_back();
//         }
//     }
//     vector<vector<int>> subsetsWithDup(vector<int>& nums) {
//         vector<int> ds;
//         vector<vector<int>> ans;
//         sort(nums.begin(),nums.end());
//         findSubsets(0, nums, ds, ans);
//         return ans;
//     }
// };
