// // Course Schedule
// // Solved
// // Medium
// // Topics
// // premium lock icon
// // Companies
// // Hint
// // There are a total of numCourses courses you have to take, labeled from 0
// to
// // numCourses - 1. You are given an array prerequisites where
// prerequisites[i] =
// // [ai, bi] indicates that you must take course bi first if you want to take
// // course ai.

// // For example, the pair [0, 1], indicates that to take course 0 you have to
// // first take course 1. Return true if you can finish all courses. Otherwise,
// // return false.

// // Example 1:

// // Input: numCourses = 2, prerequisites = [[1,0]]
// // Output: true
// // Explanation: There are a total of 2 courses to take.
// // To take course 1 you should have finished course 0. So it is possible.
// // Example 2:

// // Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
// // Output: false
// // Explanation: There are a total of 2 courses to take.
// // To take course 1 you should have finished course 0, and to take course 0
// you
// // should also have finished course 1. So it is impossible.

// // Constraints:

// // 1 <= numCourses <= 2000
// // 0 <= prerequisites.length <= 5000
// // prerequisites[i].length == 2
// // 0 <= ai, bi < numCourses
// // All the pairs prerequisites[i] are unique.

// class Solution {
// public:
//     bool dfs(int node, vector<vector<int>>& adj, vector<int>& vis,
//              vector<int>& pathVis) {
//         vis[node] = 1;
//         pathVis[node] = 1;

//         for (auto adjacentNode : adj[node]) {
//             if (!vis[adjacentNode]) {
//                 if (dfs(adjacentNode, adj, vis, pathVis)) {
//                     return true;
//                 }
//             } else if (pathVis[adjacentNode]) {
//                 return true;
//             }
//         }

//         pathVis[node] = 0;
//         return false;
//     }

//     bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
//         vector<int> vis(numCourses, 0);
//         vector<int> pathVis(numCourses, 0);

//       // Build adjacency list first
//         vector<vector<int>> adj(numCourses);

//         for (auto &p : prerequisites) {
//             adj[p[1]].push_back(p[0]); // b → a
//         }

//         for (int i = 0; i < numCourses; i++) {
//             if (!vis[i]) {
//                 if (dfs(i, adj, vis, pathVis)) {
//                     return false; // cycle Cant Finish
//                 }
//             }
//         }
//         return true;
//     }
// };