// //  Combination Sum II
// // Solved
// // Medium
// // Topics
// // premium lock icon
// // Companies
// // Given a collection of candidate numbers (candidates) and a target number
// (target), find all unique combinations in candidates where the candidate
// numbers sum to target.

// // Each number in candidates may only be used once in the combination.

// // Note: The solution set must not contain duplicate combinations.

// // Example 1:

// // Input: candidates = [10,1,2,7,6,1,5], target = 8
// // Output:
// // [
// // [1,1,6],
// // [1,2,5],
// // [1,7],
// // [2,6]
// // ]
// // Example 2:

// // Input: candidates = [2,5,2,1,2], target = 5
// // Output:
// // [
// // [1,2,2],
// // [5]
// // ]

// class Solution {
// public:
//     void findCombinations(int index, int target, vector<int> &candidates,
//                      vector<vector<int>> &ans, vector<int> &ds) {
//         int n = candidates.size();
//         if (target == 0) {
//             ans.push_back(ds);
//         }
//         for (int i = index; i < n; i++) {
//             if (i > index && candidates[i] == candidates[i - 1])
//                 continue;
//             if (candidates[i] > target) {
//                 break;
//             }
//             ds.push_back(candidates[i]);
//             findCombinations(i + 1, target - candidates[i],candidates, ans,
//             ds); ds.pop_back();
//         }
//     }
//     vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
//     {
//         sort(candidates.begin(), candidates.end());
//         vector<vector<int>> ans;
//         vector<int> ds;
//         findCombinations(0, target, candidates, ans, ds);
//         return ans;
//     }
// };