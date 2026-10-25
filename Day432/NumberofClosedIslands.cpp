// // 1254. Number of Closed Islands
// // Solved
// // Medium
// // Topics
// // premium lock icon
// // Companies
// // Hint
// // Given a 2D grid consists of 0s (land) and 1s (water).  An island is a
// maximal
// // 4-directionally connected group of 0s and a closed island is an island
// // totally (all left, top, right, bottom) surrounded by 1s.

// // Return the number of closed islands.

// // Example 1:

// // Input: grid =
// //
// [[1,1,1,1,1,1,1,0],[1,0,0,0,0,1,1,0],[1,0,1,0,1,1,1,0],[1,0,0,0,0,1,0,1],[1,1,1,1,1,1,1,0]]
// // Output: 2
// // Explanation:
// // Islands in gray are closed because they are completely surrounded by water
// // (group of 1s). Example 2:

// // Input: grid = [[0,0,1,0,0],[0,1,0,1,0],[0,1,1,1,0]]
// // Output: 1
// // Example 3:

// // Input: grid = [[1,1,1,1,1,1,1],
// //                [1,0,0,0,0,0,1],
// //                [1,0,1,1,1,0,1],
// //                [1,0,1,0,1,0,1],
// //                [1,0,1,1,1,0,1],
// //                [1,0,0,0,0,0,1],
// //                [1,1,1,1,1,1,1]]
// // Output: 2

// // Constraints:

// // 1 <= grid.length, grid[0].length <= 100
// // 0 <= grid[i][j] <=1

// class Solution {
// public:
//     int closedIsland(vector<vector<int>>& grid) {
//         int m = grid.size();
//         int n = grid[0].size();
//         vector<vector<bool>> visit(m, vector<bool>(n));
//         int count = 0;
//         for (int i = 0; i < m; i++) {
//             for (int j = 0; j < n; j++) {
//                 if (grid[i][j] == 0 && !visit[i][j] &&
//                     bfs(i, j, m, n, grid, visit)) {
//                     count++;
//                 }
//             }
//         }
//         return count;
//     }

//     bool bfs(int x, int y, int m, int n, vector<vector<int>>& grid,
//              vector<vector<bool>>& visit) {
//         queue<pair<int, int>> q;
//         q.push({x, y});
//         visit[x][y] = 2;
//         bool isClosed = true;

//         vector<int> dirx{0, 1, 0, -1};
//         vector<int> diry{-1, 0, 1, 0};

//         while (!q.empty()) {
//             x = q.front().first;  // row nnumber
//             y = q.front().second; // column number
//             q.pop();

//             for (int i = 0; i < 4; i++) {
//                 int r = x + dirx[i];
//                 int c = y + diry[i];
//                 if (r < 0 || r >= m || c < 0 || c >= n) {
//                     // (x, y) is a boundary cell.
//                     isClosed = false;
//                 } else if (grid[r][c] == 0 && !visit[r][c]) {
//                     q.push({r, c});
//                     visit[r][c] = true;
//                 }
//             }
//         }

//         return isClosed;
//     }
// };