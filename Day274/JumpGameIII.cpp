// // Jump Game III
// // Solved
// // Medium
// // Topics
// // premium lock icon
// // Companies
// // Hint
// // Given an array of non-negative integers arr, you are initially positioned
// at
// // start index of the array. When you are at index i, you can jump to i +
// arr[i]
// // or i - arr[i], check if you can reach any index with value 0.

// // Notice that you can not jump outside of the array at any time.

// // Example 1:

// // Input: arr = [4,2,3,0,3,1,2], start = 5
// // Output: true
// // Explanation:
// // All possible ways to reach at index 3 with value 0 are:
// // index 5 -> index 4 -> index 1 -> index 3
// // index 5 -> index 6 -> index 4 -> index 1 -> index 3
// // Example 2:

// // Input: arr = [4,2,3,0,3,1,2], start = 0
// // Output: true
// // Explanation:
// // One possible way to reach at index 3 with value 0 is:
// // index 0 -> index 4 -> index 1 -> index 3
// // Example 3:

// // Input: arr = [3,0,2,1,2], start = 2
// // Output: false
// // Explanation: There is no way to reach at index 1 with value 0.

// // Constraints:

// // 1 <= arr.length <= 5 * 104
// // 0 <= arr[i] < arr.length
// // 0 <= start < arr.length

// class Solution {
// public:
//     bool bfs(int start, vector<int>& vis, vector<int>& arr) {
//         int n = arr.size();
//         queue<int> q;
//         q.push(start);
//         vis[start] = 1;

//         while (!q.empty()) {
//             int node = q.front();
//             q.pop();

//             // Reached value 0
//             if (arr[node] == 0) {
//                 return true;
//             }
//             int forward = node + arr[node];
//             int backward = node - arr[node];

//             if (forward < n && !vis[forward]) {
//                 vis[forward] = 1;
//                 q.push(forward);
//             }
//              if (backward >= 0 && !vis[backward]) {
//                 vis[backward] = 1;
//                 q.push(backward);
//             }
//         }

//         return false;
//     }
//     bool canReach(vector<int>& arr, int start) {
//         int n = arr.size();
//         vector<int> vis(n, 0);
//         return bfs(start, vis, arr);
//     }
// };