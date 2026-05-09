// // Cyclically Rotating a Grid
// // Solved
// // Medium
// // Topics
// // premium lock icon
// // Companies
// // Hint
// // You are given an m x n integer matrix grid​​​, where m and n are
// both
// // even integers, and an integer k.

// // The matrix is composed of several layers, which is shown in the below
// image,
// // where each color is its own layer:

// // A cyclic rotation of the matrix is done by cyclically rotating each layer
// in
// // the matrix. To cyclically rotate a layer once, each element in the layer
// will
// // take the place of the adjacent element in the counter-clockwise direction.
// An
// // example rotation is shown below:

// // Return the matrix after applying k cyclic rotations to it.

// // Example 1:

// // Input: grid = [[40,10],[30,20]], k = 1
// // Output: [[10,20],[40,30]]
// // Explanation: The figures above represent the grid at every state.
// // Example 2:

// // Input: grid = [[1,2,3,4],[5,6,7,8],[9,10,11,12],[13,14,15,16]], k = 2
// // Output: [[3,4,8,12],[2,11,10,16],[1,7,6,15],[5,9,13,14]]
// // Explanation: The figures above represent the grid at every state.

// // Constraints:

// // m == grid.length
// // n == grid[i].length
// // 2 <= m, n <= 50
// // Both m and n are even integers.
// // 1 <= grid[i][j] <= 5000
// // 1 <= k <= 109

// class Solution {
// public:
//     vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
//         int n = grid.size();
//         int m = grid[0].size();
//         // Because every layer removes one boundary from all sides.
//         int layers = min(m, n) / 2;

//         for (int layer = 0; layer < layers; layer++) {
//             vector<int> arr;
//             int top = layer;
//             int left = layer;
//             int bottom = n - layer - 1;
//             int right = m - layer - 1;

//             // top row
//             for (int col = left; col <= right; col++) {
//                 arr.push_back(grid[top][col]);
//             }

//             // right column
//             for (int row = top + 1; row <= bottom - 1; row++) {
//                 arr.push_back(grid[row][right]);
//             }

//             // bottom row
//             for (int col = right; col >= left; col--) {
//                 arr.push_back(grid[bottom][col]);
//             }

//             // left column
//             for (int row = bottom - 1; row >= top + 1; row--) {
//                 arr.push_back(grid[row][left]);
//             }

//             // Now we have Layer in Arr
//             // we need to rotate it

//             int len = arr.size();
//             int rotate = k % len;

//             vector<int> rotated(len);
//             for (int i = 0; i < len; i++) {
//                 rotated[i] = arr[(i + rotate) % len];
//             }

//             // Put rotated values back.
//             int idx = 0;
//             // top row
//             for (int col = left; col <= right; col++) {
//                 grid[top][col] = rotated[idx];
//                 idx++;
//             }

//             // right column
//             for (int row = top + 1; row <= bottom - 1; row++) {
//                 grid[row][right] = rotated[idx];
//                 idx++;
//             }

//             // bottom row
//             for (int col = right; col >= left; col--) {
//                 grid[bottom][col] = rotated[idx];
//                 idx++;
//             }

//             // left column
//             for (int row = bottom - 1; row >= top + 1; row--) {
//                 grid[row][left] = rotated[idx];
//                 idx++;
//             }
//         }

//         return grid;
//     }
// };