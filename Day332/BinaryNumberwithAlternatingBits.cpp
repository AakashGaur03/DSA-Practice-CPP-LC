// // 693. Binary Number with Alternating Bits
// // Solved
// // Easy
// // Topics
// // premium lock icon
// // Companies
// // Given a positive integer, check whether it has alternating bits: namely,
// if
// // two adjacent bits will always have different values.

// // Example 1:

// // Input: n = 5
// // Output: true
// // Explanation: The binary representation of 5 is: 101
// // Example 2:

// // Input: n = 7
// // Output: false
// // Explanation: The binary representation of 7 is: 111.
// // Example 3:

// // Input: n = 11
// // Output: false
// // Explanation: The binary representation of 11 is: 1011.

// // Constraints:

// // 1 <= n <= 231 - 1

// class Solution {
// public:
//     bool hasAlternatingBits(int n) {

//         // XOR the number with itself shifted by one bit.
//         // If the bits are alternating (e.g., 1010 or 0101),
//         // the result will be all 1s.
//         unsigned int x = n ^ (n >> 1);
//         // A number consisting of all 1s has the property:
//         // x & (x + 1) == 0
//         // Example:
//         // x     = 1111
//         // x + 1 = 10000
//         // AND   = 00000
//         // If this condition is true, n has alternating bits.
//         return (x & (x + 1)) == 0;
//     }
// };