// // Jump Game IV
// // Hard
// // Topics
// // premium lock icon
// // Companies
// // Hint
// // Given an array of integers arr, you are initially positioned at the first
// // index of the array.

// // In one step you can jump from index i to index:

// // i + 1 where: i + 1 < arr.length.
// // i - 1 where: i - 1 >= 0.
// // j where: arr[i] == arr[j] and i != j.
// // Return the minimum number of steps to reach the last index of the array.

// // Notice that you can not jump outside of the array at any time.

// // Example 1:

// // Input: arr = [100,-23,-23,404,100,23,23,23,3,404]
// // Output: 3
// // Explanation: You need three jumps from index 0 --> 4 --> 3 --> 9. Note
// that
// // index 9 is the last index of the array. Example 2:

// // Input: arr = [7]
// // Output: 0
// // Explanation: Start index is the last index. You do not need to jump.
// // Example 3:

// // Input: arr = [7,6,9,6,9,6,9,7]
// // Output: 1
// // Explanation: You can jump directly from index 0 to index 7 which is last
// // index of the array.

// // Constraints:

// // 1 <= arr.length <= 5 * 104
// // -108 <= arr[i] <= 108

// class Solution {
// public:
//     int bfs(vector<int>& arr, unordered_map<int, vector<int>>& mp,
//             queue<int>& q, vector<int>& vis) {
//         int n = arr.size();
//         int steps = 0;

//         while (!q.empty()) {
//             int size = q.size();

//             // process one BFS level
//             while (size--) {
//                 int node = q.front();
//                 q.pop();

//                 // Destination
//                 if (node == n - 1) {
//                     return steps;
//                 }

//                 // Left Jump
//                 if (node - 1 >= 0 && !vis[node - 1]) {
//                     vis[node - 1] = 1;
//                     q.push(node - 1);
//                 }

//                 // Right Jump
//                 if (node + 1 < n && !vis[node + 1]) {
//                     vis[node + 1] = 1;
//                     q.push(node + 1);
//                 }
//                 // Same Value Jump
//                 for (auto it : mp[arr[node]]) {
//                     if (!vis[it]) {
//                         vis[it] = 1;
//                         q.push(it);
//                     }
//                 }
//                 mp.erase(arr[node]);
//             }
//             steps++;
//         }
//         return -1;
//     }

//     int minJumps(vector<int>& arr) {
//         int n = arr.size();
//         if (n == 1)
//             return 0;
//         queue<int> q;
//         vector<int> vis(n, 0);

//         unordered_map<int, vector<int>> mp;

//         for (int i = 0; i < n; i++) {
//             mp[arr[i]].push_back(i);
//         }
//         q.push(0);
//         vis[0] = 1;

//         return bfs(arr, mp, q, vis);
//     }
// };