// // 827. Making A Large Island
// // Solved
// // Hard
// // Topics
// // premium lock icon
// // Companies
// // You are given an n x n binary matrix grid. You are allowed to change at
// most
// // one 0 to be 1.

// // Return the size of the largest island in grid after applying this
// operation.

// // An island is a 4-directionally connected group of 1s.

// // Example 1:

// // Input: grid = [[1,0],[0,1]]
// // Output: 3
// // Explanation: Change one 0 to 1 and connect two 1s, then we get an island
// with
// // area = 3. Example 2:

// // Input: grid = [[1,1],[1,0]]
// // Output: 4
// // Explanation: Change the 0 to 1 and make the island bigger, only one island
// // with area = 4. Example 3:

// // Input: grid = [[1,1],[1,1]]
// // Output: 4
// // Explanation: Can't change any 0 to 1, only one island with area = 4.

// // Constraints:

// // n == grid.length
// // n == grid[i].length
// // 1 <= n <= 500
// // grid[i][j] is either 0 or 1.

// class Solution {
// public:
//     class DisjointSet {
//     public:
//         vector<int> parent, size;
//         DisjointSet(int n) {
//             parent.resize(n + 1);
//             size.resize(n + 1);
//             for (int i = 0; i < n; i++) {
//                 parent[i] = i;
//                 size[i] = 1;
//             }
//         }
//         int findUPar(int node) {
//             if (node == parent[node]) {
//                 return node;
//             }

//             return parent[node] = findUPar(parent[node]);
//         }

//         void unionBySize(int u, int v) {
//             int ulp_u = findUPar(u);
//             int ulp_v = findUPar(v);
//             if (ulp_u == ulp_v) {
//                 // Already belong to same component
//                 return;
//             }
//             if (size[ulp_u] < size[ulp_v]) {
//                 parent[ulp_u] = ulp_v;
//                 size[ulp_v] += size[ulp_u];
//             } else {
//                 parent[ulp_v] = ulp_u;
//                 size[ulp_u] += size[ulp_v];
//             }
//         }
//     };

//     bool isValid(int adjRow, int adjCol, int n) {
//         return adjRow >= 0 && adjRow < n && adjCol >= 0 && adjCol < n;
//     }

//     int largestIsland(vector<vector<int>>& grid) {
//         int n = grid.size();
//         DisjointSet ds(n * n);
//         // Step 1 Connect All Existing Components
//         for (int row = 0; row < n; row++) {
//             for (int col = 0; col < n; col++) {
//                 if (grid[row][col] == 0) {
//                     continue;
//                 }
//                 vector<int> dr = {-1, 0, 1, 0};
//                 vector<int> dc = {0, -1, 0, 1};

//                 for (int i = 0; i < 4; i++) {
//                     int adjr = row + dr[i];
//                     int adjc = col + dc[i];

//                     if (isValid(adjr, adjc, n) && grid[adjr][adjc] == 1) {
//                         int nodeNumber = row * n + col;
//                         int adjNodeNumber = adjr * n + adjc;
//                         ds.unionBySize(nodeNumber, adjNodeNumber);
//                     }
//                 }
//             }
//         }
//         int maxi = 0;
//         // Step 2 Covnert 0s to 1s
//         for (int row = 0; row < n; row++) {
//             for (int col = 0; col < n; col++) {
//                 if (grid[row][col] == 1) {
//                     continue;
//                 }
//                 vector<int> dr = {-1, 0, 1, 0};
//                 vector<int> dc = {0, -1, 0, 1};
//                 set<int> components;
//                 for (int i = 0; i < 4; i++) {
//                     int adjr = row + dr[i];
//                     int adjc = col + dc[i];
//                     if (isValid(adjr, adjc, n)) {
//                         if (grid[adjr][adjc] == 1) {
//                             int adjNodeNumber = adjr * n + adjc;
//                             components.insert(ds.findUPar(adjNodeNumber));
//                         }
//                     }
//                 }
//                 int sizeTotal =
//                     1; // We start from 1 as we are converting 0 to 1
//                 for (auto it : components) {
//                     sizeTotal += ds.size[it];
//                 }
//                 maxi = max(maxi, sizeTotal);
//             }
//         }
//         // If all are Ones
//         for (int cellNo = 0; cellNo < n * n; cellNo++) {
//             maxi = max(maxi, ds.size[ds.findUPar(cellNo)]);
//         }
//         return maxi;
//     }
// };