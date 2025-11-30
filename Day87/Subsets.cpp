// // Subsets
// // Solved
// // Medium
// // Topics
// // premium lock icon
// // Companies
// // Given an integer array nums of unique elements, return all possible
// subsets (the power set).

// // The solution set must not contain duplicate subsets. Return the solution
// in any order.

// // Example 1:

// // Input: nums = [1,2,3]
// // Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
// // Example 2:

// // Input: nums = [0]
// // Output: [[],[0]]

// // Constraints:

// // 1 <= nums.length <= 10
// // -10 <= nums[i] <= 10
// // All the numbers of nums are unique.

// class Solution {
// public:
// void findSubsets(int index,vector<int> &nums,vector<vector<int>> &ans,
// vector<int>&ds){
//     int n = nums.size();
//     if(index == n){
//         ans.push_back(ds);
//         return;
//     }

//     ds.push_back(nums[index]);
//     findSubsets(index+1,nums,ans,ds);
//     ds.pop_back();
//     findSubsets(index+1,nums,ans,ds);
// }
//     vector<vector<int>> subsets(vector<int>& nums) {
//         vector<vector<int>> ans;
//         vector<int> ds;
//          findSubsets(0,nums,ans,ds);
//         return ans;
//     }
// };