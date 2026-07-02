// // 3286. Find a Safe Walk Through a Grid
// // Medium
// // Topics
// // premium lock icon
// // Companies
// // Hint
// // You are given an m x n binary matrix grid and an integer health.

// // You start on the upper-left corner (0, 0) and would like to get to the
// // lower-right corner (m - 1, n - 1).

// // You can move up, down, left, or right from one cell to another adjacent
// cell
// // as long as your health remains positive.

// // Cells (i, j) with grid[i][j] = 1 are considered unsafe and reduce your
// health
// // by 1.

// // Return true if you can reach the final cell with a health value of 1 or
// more,
// // and false otherwise.

// // Example 1:

// // Input: grid = [[0,1,0,0,0],[0,1,0,1,0],[0,0,0,1,0]], health = 1

// // Output: true

// // Explanation:

// // The final cell can be reached safely by walking along the gray cells
// below.

// // Example 2:

// // Input: grid = [[0,1,1,0,0,0],[1,0,1,0,0,0],[0,1,1,1,0,1],[0,0,1,0,1,0]],
// // health = 3

// // Output: false

// // Explanation:

// // A minimum of 4 health points is needed to reach the final cell safely.

// // Example 3:

// // Input: grid = [[1,1,1],[1,0,1],[1,1,1]], health = 5

// // Output: true

// // Explanation:

// // The final cell can be reached safely by walking along the gray cells
// below.

// // Any path that does not go through the cell (1, 1) is unsafe since your
// health
// // will drop to 0 when reaching the final cell.

// class Solution {
// public:
//     bool findSafeWalk(vector<vector<int>>& grid, int health) {
//         int m = grid.size();
//         int n = grid[0].size();

//         vector<vector<int>> best(m, vector<int>(n, -1));

//         int startHealth = health - grid[0][0];
//         if (startHealth <= 0) {
//             return false;
//         }

//         queue<pair<pair<int, int>, int>> q;
//         q.push({{0, 0}, startHealth});
//         best[0][0] = startHealth;

//         vector<int> dr = {-1, 0, 1, 0};
//         vector<int> dc = {0, 1, 0, -1};

//         while (!q.empty()) {
//             auto cur = q.front();
//             q.pop();
//             int r = cur.first.first;
//             int c = cur.first.second;
//             int hp = cur.second;

//             if (r == m - 1 && c == n - 1)
//                 return true;

//             for (int k = 0; k < 4; k++) {
//                 int nr = r + dr[k];
//                 int nc = c + dc[k];

//                 if (nr < 0 || nr >= m || nc < 0 || nc >= n)
//                     continue;
//                 int nhp = hp - grid[nr][nc];

//                 if (nhp <= 0)
//                     continue;

//                 if (nhp > best[nr][nc]) {
//                     // This means we've already reached (2,3) with 5 health
//                     // remaining. Later, another path reaches (2,3) with: nhp
//                     =
//                     // 3 Should we explore from here? No.
//                     best[nr][nc] = nhp;
//                     q.push({{nr, nc}, nhp});
//                 }
//             }
//         }
//         return false;
//     }
// };