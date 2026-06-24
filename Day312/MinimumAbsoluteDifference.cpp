// // 1200. Minimum Absolute Difference
// // Solved
// // Easy
// // Topics
// // premium lock icon
// // Companies
// // Hint
// // Given an array of distinct integers arr, find all pairs of elements with
// the
// // minimum absolute difference of any two elements.

// // Return a list of pairs in ascending order(with respect to pairs), each
// pair
// // [a, b] follows

// // a, b are from arr
// // a < b
// // b - a equals to the minimum absolute difference of any two elements in arr

// // Example 1:

// // Input: arr = [4,2,1,3]
// // Output: [[1,2],[2,3],[3,4]]
// // Explanation: The minimum absolute difference is 1. List all pairs with
// // difference equal to 1 in ascending order. Example 2:

// // Input: arr = [1,3,6,10,15]
// // Output: [[1,3]]
// // Example 3:

// // Input: arr = [3,8,-10,23,19,-4,-14,27]
// // Output: [[-14,-10],[19,23],[23,27]]

// class Solution {
// public:
//     vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
//         int n = arr.size();
//         sort(arr.begin(), arr.end());
//         int min_diff = arr[1] - arr[0];
//         for (int i = 0; i < n - 1; i++) {
//             min_diff = min(min_diff, arr[i + 1] - arr[i]);
//         }
//         vector<vector<int>> sol;
//         for (int i = 0; i < n - 1; i++) {
//             if (arr[i + 1] - arr[i] == min_diff) {
//                 sol.push_back({arr[i], arr[i + 1]});
//             }
//         }
//         return sol;
//     }
// };