// // 1319. Number of Operations to Make Network Connected
// // Solved
// // Medium
// // Topics
// // premium lock icon
// // Companies
// // Hint
// // There are n computers numbered from 0 to n - 1 connected by ethernet
// cables
// // connections forming a network where connections[i] = [ai, bi] represents a
// // connection between computers ai and bi. Any computer can reach any other
// // computer directly or indirectly through the network.

// // You are given an initial computer network connections. You can extract
// // certain cables between two directly connected computers, and place them
// // between any pair of disconnected computers to make them directly
// connected.

// // Return the minimum number of times you need to do this in order to make
// all
// // the computers connected. If it is not possible, return -1.

// // Example 1:

// // Input: n = 4, connections = [[0,1],[0,2],[1,2]]
// // Output: 1
// // Explanation: Remove cable between computer 1 and 2 and place between
// // computers 1 and 3. Example 2:

// // Input: n = 6, connections = [[0,1],[0,2],[0,3],[1,2],[1,3]]
// // Output: 2
// // Example 3:

// // Input: n = 6, connections = [[0,1],[0,2],[0,3],[1,2]]
// // Output: -1
// // Explanation: There are not enough cables.

// // Constraints:

// // 1 <= n <= 105
// // 1 <= connections.length <= min(n * (n - 1) / 2, 105)
// // connections[i].length == 2
// // 0 <= ai, bi < n
// // ai != bi
// // There are no repeated connections.
// // No two computers are connected by more than one cable.

// class Solution {
// public:
// class DisjointSet{
//         vector<int> parent, size;

//     public:
//         DisjointSet(int n) {
//             parent.resize(n + 1);
//             size.resize(n + 1);

//             for (int i = 0; i <= n; i++) {
//                 parent[i] =
//                     i; // In Parent Initally everything is set as themselves
//                 size[i] = 1; // In Size Initally everything is set as 1
//             }
//         }
//         int findUPar(int node) {
//             if (node == parent[node]) {
//                 return node;
//             }
//             // return findUPar(parent[node]); // Normal Recurssion
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
// };

//     int makeConnected(int n, vector<vector<int>>& connections) {
//         DisjointSet ds(n);
//         int cntExtra = 0;

//         for (auto it : connections) {
//             int u = it[0];
//             int v = it[1];

//             if (ds.findUPar(u) == ds.findUPar(v)) {
//                 cntExtra++;
//             } else {
//                 ds.unionBySize(u, v);
//             }
//         }
//         int connectedComp = 0;
//         for (int i = 0; i < n; i++) {
//             if (ds.findUPar(i) == i) {
//                 connectedComp++;
//             }
//         }
//         int ans = connectedComp - 1;
//         if (cntExtra >= ans) {
//             return ans;
//         } else {
//             return -1;
//         }
//     }
// };