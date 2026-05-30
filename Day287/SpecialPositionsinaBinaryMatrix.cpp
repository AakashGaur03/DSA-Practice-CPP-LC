// // Special Positions in a Binary Matrix
// // Solved
// // Easy
// // Topics
// // premium lock icon
// // Companies
// // Hint
// // Given an m x n binary matrix mat, return the number of special positions
// in
// // mat.

// // A position (i, j) is called special if mat[i][j] == 1 and all other
// elements
// // in row i and column j are 0 (rows and columns are 0-indexed).

// // Example 1:

// // Input: mat = [[1,0,0],[0,0,1],[1,0,0]]
// // Output: 1
// // Explanation: (1, 2) is a special position because mat[1][2] == 1 and all
// // other elements in row 1 and column 2 are 0. Example 2:

// // Input: mat = [[1,0,0],[0,1,0],[0,0,1]]
// // Output: 3
// // Explanation: (0, 0), (1, 1) and (2, 2) are special positions.

// // Constraints:

// // m == mat.length
// // n == mat[i].length
// // 1 <= m, n <= 100
// // mat[i][j] is either 0 or 1.

// class Solution {
// public:
//     bool checkIfAllZero(int i, int j, vector<vector<int>>& mat) {
//         int n = mat.size();
//         int m = mat[0].size();

//         // Check row
//         for (int k = 0; k < m; k++) {
//             if (k != j && mat[i][k] == 1) {
//                 return false;
//             }
//         }

//         // Check column
//         for (int k = 0; k < n; k++) {
//             if (k != i && mat[k][j] == 1) {
//                 return false;
//             }
//         }

//         return true;
//     }
//     int numSpecial(vector<vector<int>>& mat) {
//         int n = mat.size();
//         int m = mat[0].size();

//         int cnt = 0;

//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < m; j++) {
//                 if (mat[i][j] == 1) {
//                     if (checkIfAllZero(i, j, mat)) {
//                         cnt++;
//                     }
//                 }
//             }
//         }

//         return cnt;
//     }
// };