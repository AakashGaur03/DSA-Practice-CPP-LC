// // Power of Three
// // Easy
// // Topics
// // premium lock icon
// // Companies
// // Given an integer n, return true if it is a power of three. Otherwise,
// return false.

// // An integer n is a power of three, if there exists an integer x such that n
// == 3x.

// // Example 1:

// // Input: n = 27
// // Output: true
// // Explanation: 27 = 33
// // Example 2:

// // Input: n = 0
// // Output: false
// // Explanation: There is no x where 3x = 0.
// // Example 3:

// // Input: n = -1
// // Output: false
// // Explanation: There is no x where 3x = (-1).

// // Constraints:

// // -231 <= n <= 231 - 1

// // Follow up: Could you solve it without loops/recursion?

// class Solution {
// public:
//     bool isPowerOfThree(int n) {
//         if (n <= 0) {
//             return false;
//         }
//         // Max value can be  3^19 in integer
//         int left = 0;
//         int right = 19;
//         while (left <= right) {
//             int mid = left + (right - left) / 2;
//             // Even though 3¹⁹ fits inside int, pow returns double
//             long long number = pow(3, mid);
//             if (number == n)
//                 return true;
//             else if (number > n) {
//                 right = mid - 1;
//             } else if (number < n) {
//                 left = mid + 1;
//             }
//         }
//         return false;
//     }
// };

// //  bool isPowerOfThree(int n) {
// //       if (n <= 0) {
// //             return false;
// //         }

// //         // The largest power of 3 that fits within a standard 32-bit
// signed
// //         integer
// //         // is 3^19, which equals 1,162,261,467.
// //         // Any power of 3 must perfectly divide this number.
// //         const int MAX_POWER_OF_THREE = 1162261467;

// //         return (MAX_POWER_OF_THREE % n) == 0;
// //     }