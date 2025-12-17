// // Power of Two
// // Solved
// // Easy
// // Topics
// // premium lock icon
// // Companies
// // Given an integer n, return true if it is a power of two. Otherwise, return
// // false.

// // An integer n is a power of two, if there exists an integer x such that n
// ==
// // 2x.

// // Example 1:

// // Input: n = 1
// // Output: true
// // Explanation: 20 = 1
// // Example 2:

// // Input: n = 16
// // Output: true
// // Explanation: 24 = 16
// // Example 3:

// // Input: n = 3
// // Output: false

// // Constraints:

// // -231 <= n <= 231 - 1

// // Follow up: Could you solve it without loops/recursion?

// class Solution {
// public:
//     bool isPowerOfTwo(int n) {
//         // n & (n-1) bit manipulation
//         // we will get power of two when only most right bit is 1
//         // n-1 will turn that to 0 and rest to 1
//         // and performing an & operator will lead to all 0s
//         if (n <= 0) return false;
//         return (n & (n-1)) == 0;
//     }
// };

// // bool isPowerOfTwo(int n) {
// //     while (n <= 0)
// //         return false;
// //     long long power = 1;
// //     while (power < n) {
// //         power *= 2;
// //     }
// //     return power == n;
// // }
