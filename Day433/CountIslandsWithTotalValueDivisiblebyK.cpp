// // 3619. Count Islands With Total Value Divisible by K
// // Solved
// // Medium
// // Topics
// // premium lock icon
// // Companies
// // Hint
// // You are given an m x n matrix grid and a positive integer k. An island is
// a
// // group of positive integers (representing land) that are 4-directionally
// // connected (horizontally or vertically).

// // The total value of an island is the sum of the values of all cells in the
// // island.

// // Return the number of islands with a total value divisible by k.

// // Example 1:

// // Input: grid =
// [[0,2,1,0,0],[0,5,0,0,5],[0,0,1,0,0],[0,1,4,7,0],[0,2,0,0,8]],
// // k = 5

// // Output: 2

// // Explanation:

// // The grid contains four islands. The islands highlighted in blue have a
// total
// // value that is divisible by 5, while the islands highlighted in red do not.

// // Example 2:

// // Input: grid = [[3,0,3,0], [0,3,0,3], [3,0,3,0]], k = 3

// // Output: 6

// // Explanation:

// // The grid contains six islands, each with a total value that is divisible
// // by 3.

// // Constraints:

// // m == grid.length
// // n == grid[i].length
// // 1 <= m, n <= 1000
// // 1 <= m * n <= 105
// // 0 <= grid[i][j] <= 106
// // 1 <= k <= 106

// class Solution {
// public:
//     long long fill(vector<vector<int>>& grid, int i, int j) {
//         if (i < 0 || j < 0 || i >= grid.size() ||
//             j >= grid[0].size() || grid[i][j] == 0)
//             return 0;

//         long long sum = grid[i][j];
//         grid[i][j] = 0;

//         sum += fill(grid, i + 1, j);
//         sum += fill(grid, i - 1, j);
//         sum += fill(grid, i, j + 1);
//         sum += fill(grid, i, j - 1);

//         return sum;
//     }

//     int countIslands(vector<vector<int>>& grid, int k) {
//         int res = 0;

//         for (int i = 0; i < grid.size(); i++) {
//             for (int j = 0; j < grid[0].size(); j++) {
//                 if (grid[i][j] > 0) {
//                     long long sum = fill(grid, i, j);

//                     if (sum % k == 0)
//                         res++;
//                 }
//             }
//         }

//         return res;
//     }
// };