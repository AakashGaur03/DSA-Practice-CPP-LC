// // 1192. Critical Connections in a Network
// // Solved
// // Hard
// // Topics
// // premium lock icon
// // Companies
// // Hint
// // There are n servers numbered from 0 to n - 1 connected by undirected
// // server-to-server connections forming a network where connections[i] = [ai,
// // bi] represents a connection between servers ai and bi. Any server can
// reach
// // other servers directly or indirectly through the network.

// // A critical connection is a connection that, if removed, will make some
// // servers unable to reach some other server.

// // Return all critical connections in the network in any order.

// // Example 1:

// // Input: n = 4, connections = [[0,1],[1,2],[2,0],[1,3]]
// // Output: [[1,3]]
// // Explanation: [[3,1]] is also accepted.
// // Example 2:

// // Input: n = 2, connections = [[0,1]]
// // Output: [[0,1]]

// // Constraints:

// // 2 <= n <= 105
// // n - 1 <= connections.length <= 105
// // 0 <= ai, bi <= n - 1
// // ai != bi
// // There are no repeated connections.

// class Solution {
// public:
//     // Global timer used to assign discovery time to each node
//     int timer = 1;
//     void dfs(int node, int parent, vector<int>& vis, vector<vector<int>>&
//     adj,
//              vector<int>& tin, vector<int>& low, vector<vector<int>>&
//              bridges) {
//         vis[node] = 1;
//         // Discovery time of current node
//         // Initially, low[node] is also the discovery time
//         tin[node] = low[node] = timer;
//         timer++;

//         for (auto it : adj[node]) {

//             // If neighbour is the parent,
//             // ignore this edge because this is the edge
//             // through which we came to the current node
//             if (it == parent) {
//                 continue;
//             }

//             if (vis[it] == 0) {
//                 // Current node becomes the parent of 'it'
//                 dfs(it, node, vis, adj, tin, low, bridges);

//                 // After DFS of child is complete,
//                 // update low[node] using low[it]
//                 //
//                 // low[it] tells us the earliest ancestor
//                 // that the subtree of 'it' can reach
//                 low[node] = min(low[node], low[it]);

//                 // If child 'it' cannot reach node or any
//                 // ancestor of node using a back edge,
//                 // then (node, it) is a bridge
//                 if (low[it] > tin[node]) {
//                     bridges.push_back({it, node});
//                 }

//             } else {

//                 // Use tin[it] because 'it' is an already
//                 // visited ancestor/back-edge node
//                 low[node] = min(tin[it], low[node]);
//             }
//         }
//     }

//     vector<vector<int>> criticalConnections(int n,
//                                             vector<vector<int>>& connections)
//                                             {
//         vector<vector<int>> adj(n);
//         for (auto it : connections) {
//             adj[it[0]].push_back(it[1]);
//             adj[it[1]].push_back(it[0]);
//         }

//         vector<int> vis(n, 0);
//         vector<int> tin(n);
//         vector<int> low(n);
//         vector<vector<int>> bridges;

//         for (int i = 0; i < n; i++) {
//             if (!vis[i]) {
//                 dfs(i, -1, vis, adj, tin, low, bridges);
//             }
//         }
//         return bridges;
//     }
// };