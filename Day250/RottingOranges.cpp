// // Rotting Oranges
// // Attempted
// // Medium
// // Topics
// // premium lock icon
// // Companies
// // You are given an m x n grid where each cell can have one of three values:

// // 0 representing an empty cell,
// // 1 representing a fresh orange, or
// // 2 representing a rotten orange.
// // Every minute, any fresh orange that is 4-directionally adjacent to a
// rotten
// // orange becomes rotten.

// // Return the minimum number of minutes that must elapse until no cell has a
// // fresh orange. If this is impossible, return -1.

// // Example 1:

// // Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
// // Output: 4
// // Example 2:

// // Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
// // Output: -1
// // Explanation: The orange in the bottom left corner (row 2, column 0) is
// never
// // rotten, because rotting only happens 4-directionally. Example 3:

// // Input: grid = [[0,2]]
// // Output: 0
// // Explanation: Since there are already no fresh oranges at minute 0, the
// answer
// // is just 0.

// // Constraints:

// // m == grid.length
// // n == grid[i].length
// // 1 <= m, n <= 10
// // grid[i][j] is 0, 1, or 2.

// class Solution {
// public:
//     int orangesRotting(vector<vector<int>>& grid) {
//         int n = grid.size();
//         int m = grid[0].size();

//         queue<pair<pair<int, int>, int >> q; // {{row,col},time}
//         vector<vector<int>> vis(n, vector<int>(m, 0));

//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < m; j++) {
//                 if (grid[i][j] == 2) {
//                     q.push({{i, j}, 0}); // All Rotten will be in queue
//                     vis[i][j] = 2;
//                 } else {
//                     vis[i][j] = 0;
//                 }
//             }
//         }
//         int tm = 0;
//         while (!q.empty()) {
//             int row = q.front().first.first;
//             int col = q.front().first.second;
//             int time = q.front().second;
//             tm = max(tm, time);
//             q.pop();
//             // Now we need to Visit all the neighbour
//             int delRow[] = {-1, 0, +1, 0};
//             int delCol[] = {0, -1, 0, +1};
//             for (int i = 0; i < 4; i++) { // Because 4 neighbours
//                 int nRow = row + delRow[i];
//                 int nCol = col + delCol[i];
//                 if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m &&
//                     vis[nRow][nCol] != 2 && grid[nRow][nCol] == 1) {
//                     q.push({{nRow, nCol}, time + 1});
//                     vis[nRow][nCol] = 2;
//                 }
//             }
//         }

//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < m; j++) {
//                 if (vis[i][j] != 2 && grid[i][j] == 1) {
//                     return -1;
//                 }
//             }
//         }

//         return tm;
//     }
// };