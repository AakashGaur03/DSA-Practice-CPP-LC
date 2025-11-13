// // Count Negative Numbers in a Sorted Matrix
// // Solved
// // Easy
// // Topics
// // premium lock icon
// // Companies
// // Hint
// // Given a m x n matrix grid which is sorted in non-increasing order both
// row-wise and column-wise, return the number of negative numbers in grid.

// // Example 1:

// // Input: grid = [[4,3,2,-1],[3,2,1,-1],[1,1,-1,-2],[-1,-1,-2,-3]]
// // Output: 8
// // Explanation: There are 8 negatives number in the matrix.
// // Example 2:

// // Input: grid = [[3,2],[1,0]]
// // Output: 0

// // Constraints:

// // m == grid.length
// // n == grid[i].length
// // 1 <= m, n <= 100
// // -100 <= grid[i][j] <= 100

// // Follow up: Could you find an O(n + m) solution?

// class Solution {
// public:
//     int countNegatives(vector<vector<int>>& grid) {
//         // TC O(n + m)
//         // Starting from bottom Left
//         int row = grid.size() - 1;
//         int col = 0;

//         int negs = 0;
//         while (row >= 0 && col < grid[0].size()) {
//             if (grid[row][col] < 0) {
//                 negs += grid[0].size() - col;
//                 row--;

//             } else {
//                 col++;
//             }
//         }
//         return negs;
//     }
// };

// // // Idea: Start from bottom-left (or top-right)
// // // Because the matrix is sorted decreasing both ways:
// // // Moving right → numbers get smaller.
// // // Moving up ↑ numbers get larger.
// // int negativesInEachRows(vector<int> cols) {
// //     int left = 0;
// //     int right = cols.size() - 1;
// //     int cnt = 0;
// //     while (left <= right) {
// //         int mid = left + (right - left) / 2;
// //         if (cols[mid] < 0) {
// //             right = mid - 1;
// //         } else {
// //             left = mid + 1;
// //         }
// //     }
// //     return cols.size() - left;
// // }
// // int countNegatives(vector<vector<int>>& grid) {
// //     // TC O(m×logn)
// //     int cntNegative = 0;
// //     int rows = grid.size();
// //     int cols = grid[0].size();

// //     for (int i = 0; i < rows; i++) {
// //         cntNegative += negativesInEachRows(grid[i]);
// //     }

// //     return cntNegative;
// // }