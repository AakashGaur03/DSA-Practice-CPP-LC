// // 947. Most Stones Removed with Same Row or Column
// // Medium
// // Topics
// // premium lock icon
// // Companies
// // On a 2D plane, we place n stones at some integer coordinate points. Each
// coordinate point may have at most one stone.

// // A stone can be removed if it shares either the same row or the same column
// as another stone that has not been removed.

// // Given an array stones of length n where stones[i] = [xi, yi] represents
// the location of the ith stone, return the largest possible number of stones
// that can be removed.

// // Example 1:

// // Input: stones = [[0,0],[0,1],[1,0],[1,2],[2,1],[2,2]]
// // Output: 5
// // Explanation: One way to remove 5 stones is as follows:
// // 1. Remove stone [2,2] because it shares the same row as [2,1].
// // 2. Remove stone [2,1] because it shares the same column as [0,1].
// // 3. Remove stone [1,2] because it shares the same row as [1,0].
// // 4. Remove stone [1,0] because it shares the same column as [0,0].
// // 5. Remove stone [0,1] because it shares the same row as [0,0].
// // Stone [0,0] cannot be removed since it does not share a row/column with
// another stone still on the plane.
// // Example 2:

// // Input: stones = [[0,0],[0,2],[1,1],[2,0],[2,2]]
// // Output: 3
// // Explanation: One way to make 3 moves is as follows:
// // 1. Remove stone [2,2] because it shares the same row as [2,0].
// // 2. Remove stone [2,0] because it shares the same column as [0,0].
// // 3. Remove stone [0,2] because it shares the same row as [0,0].
// // Stones [0,0] and [1,1] cannot be removed since they do not share a
// row/column with another stone still on the plane.
// // Example 3:

// // Input: stones = [[0,0]]
// // Output: 0
// // Explanation: [0,0] is the only stone on the plane, so you cannot remove
// it.

// // Constraints:

// // 1 <= stones.length <= 1000
// // 0 <= xi, yi <= 104
// // No two stones are at the same coordinate point.

// class Solution {
// public:
//     class DisjointSet {

//     public:
//         vector<int> parent, size;
//         DisjointSet(int n) {
//             parent.resize(n + 1);
//             size.resize(n + 1);
//             for (int i = 0; i <= n; i++) {
//                 parent[i] =
//                     i; // In Parent Initally everything is set as themselves
//                 size[i] = 1; // In Size Initally everything is set as 1
//             }
//         }

//         int findUPar(int node) { // Ultimate Parent
//             if (node == parent[node]) {
//                 return node;
//             }

//             // return findUPar(parent[node]); // Normal Recursion

//             return parent[node] = findUPar(parent[node]); // Path Compression
//         }

//         void unionBySize(int u, int v) {
//             int ulp_u = findUPar(u);
//             int ulp_v = findUPar(v);

//             if (ulp_u == ulp_v) {
//                 // Already belong to same component
//                 return;
//             }

//             if (size[ulp_u] < size[ulp_v]) {
//                 // Means u gets attached to v as v is greater
//                 parent[ulp_u] = ulp_v;
//                 // when we attach to v so size of V will be increased by U
//                 size[ulp_v] += size[ulp_u];
//             } else {
//                 // rank[ulp_v] == rank[ulp_u] || rank[ulp_v] < rank[ulp_u]
//                 // We can attach v to u in both cases
//                 parent[ulp_v] = ulp_u;
//                 // when we attach to U so size of U will be increased by V
//                 size[ulp_u] += size[ulp_v];
//             }
//         }
//     };

//     int removeStones(vector<vector<int>>& stones) {
//         int n = stones.size();
//         int maxRow = 0;
//         int maxCol = 0;

//         for (auto it : stones) {
//             maxRow = max(maxRow, it[0]);
//             maxCol = max(maxCol, it[1]);
//         }

//         DisjointSet ds(maxRow + maxCol + 1);
//         unordered_map<int, int> stoneNodes;
//         for (auto it : stones) {
//             int nodeRow = it[0];
//             int nodeCol = it[1] + maxRow + 1;
//             ds.unionBySize(nodeRow, nodeCol);
//             stoneNodes[nodeRow] = 1;
//             stoneNodes[nodeCol] = 1;
//         }
//         int cnt = 0;
//         for (auto it : stoneNodes) {
//             if (ds.findUPar(it.first) == it.first) {
//                 cnt++;
//             }
//         }

//         return n - cnt;
//     }
// };