// // 1091. Shortest Path in Binary Matrix
// // Solved
// // Medium
// // Topics
// // premium lock icon
// // Companies
// // Hint
// // Given an n x n binary matrix grid, return the length of the shortest clear
// // path in the matrix. If there is no clear path, return -1.

// // A clear path in a binary matrix is a path from the top-left cell (i.e.,
// (0,
// // 0)) to the bottom-right cell (i.e., (n - 1, n - 1)) such that:

// // All the visited cells of the path are 0.
// // All the adjacent cells of the path are 8-directionally connected (i.e.,
// they
// // are different and they share an edge or a corner). The length of a clear
// path
// // is the number of visited cells of this path.

// // Example 1:

// // Input: grid = [[0,1],[1,0]]
// // Output: 2
// // Example 2:

// // Input: grid = [[0,0,0],[1,1,0],[1,1,0]]
// // Output: 4
// // Example 3:

// // Input: grid = [[1,0,0],[1,1,0],[1,1,0]]
// // Output: -1

// // Constraints:

// // n == grid.length
// // n == grid[i].length
// // 1 <= n <= 100
// // grid[i][j] is 0 or 1

// class Solution {
// public:
//     int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

//         pair<int, int> source = {0, 0};
//         int n = grid.size();
//         pair<int, int> destination = {n - 1, n - 1};
//         if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
//             return -1;
//         if (n == 1)
//             return 1;
//         queue<pair<int, pair<int, int>>> q; // {dist,{i,j}}
//         vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
//         dist[source.first][source.second] = 1;      // dist[0][0] = 1;
//         q.push({1, {source.first, source.second}}); // {1,{0,0}}

//         vector<int> delRow = {-1, -1, -1, 0, 0, 1, 1, 1};
//         vector<int> delCol = {-1, 0, 1, -1, 1, -1, 0, 1};

//         while (!q.empty()) {
//             auto it = q.front();
//             q.pop();
//             int distance = it.first;
//             int row = it.second.first;
//             int col = it.second.second;
//             for (int i = 0; i < 8; i++) {
//                 int newRow = row + delRow[i];
//                 int newCol = col + delCol[i];

//                 if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < n &&
//                     grid[newRow][newCol] == 0 &&
//                     distance + 1 < dist[newRow][newCol]) {
//                     dist[newRow][newCol] = distance + 1;
//                     if (newRow == destination.first &&
//                         newCol == destination.second) {
//                         return distance + 1;
//                     }
//                     q.push({distance + 1, {newRow, newCol}});
//                 }
//             }
//         }
//         return -1;
//     }
// };