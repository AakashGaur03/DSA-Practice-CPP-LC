// // 342. Power of Four
// // Solved
// // Easy
// // Topics
// // premium lock icon
// // Companies
// // Given an integer n, return true if it is a power of four. Otherwise,
// return
// // false.

// // An integer n is a power of four, if there exists an integer x such that n
// ==
// // 4x.

// // Example 1:

// // Input: n = 16
// // Output: true
// // Example 2:

// // Input: n = 5
// // Output: false
// // Example 3:

// // Input: n = 1
// // Output: true

// class Solution {
// public:
//     bool isPowerOfFour(int n) {
//         if (n == 1) return true;
//         int x = 1;
//         for(int i=0;i<=15;i++){
//             int powerOfFour = pow(4,i);
//             if(powerOfFour == n){
//                 return true;
//             }
//             if(powerOfFour > n){
//                 return false;
//             }
//         }
//         return false;
//     }
// };