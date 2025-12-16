// // Count Good Numbers
// // Solved
// // Medium
// // Topics
// // premium lock icon
// // Companies
// // Hint
// // A digit string is good if the digits (0-indexed) at even indices are even
// and
// // the digits at odd indices are prime (2, 3, 5, or 7).

// // For example, "2582" is good because the digits (2 and 8) at even positions
// // are even and the digits (5 and 2) at odd positions are prime. However,
// "3245"
// // is not good because 3 is at an even index but is not even. Given an
// integer
// // n, return the total number of good digit strings of length n. Since the
// // answer may be large, return it modulo 109 + 7.

// // A digit string is a string consisting of digits 0 through 9 that may
// contain
// // leading zeros.

// // Example 1:

// // Input: n = 1
// // Output: 5
// // Explanation: The good numbers of length 1 are "0", "2", "4", "6", "8".
// // Example 2:

// // Input: n = 4
// // Output: 400
// // Example 3:

// // Input: n = 50
// // Output: 564908303

// // Constraints:

// // 1 <= n <= 1015

// class Solution {
// public:
//     long long recursivePow(long long x, long long n, long long ans,long long
//     MOD) {
//         // This is simply idea of recursive Power function
//         // Just added the concept of Modulo as the numbers are too big
//         // So to prevent overflow
//         if (n == 0)
//             return ans;

//         if (n % 2 != 0) {
//             ans = (ans * x) % MOD;
//             n--;
//             return recursivePow(x, n, ans,MOD);
//         } else {
//             x = (x * x) % MOD;
//             n /= 2;
//             return recursivePow(x, n, ans,MOD);
//         }
//     }
//     int countGoodNumbers(long long n) {
//         long long evenCount = (n + 1) / 2;
//         long long oddCount = (n) / 2;
//         long long MOD = 1e9 + 7;

//         long long part1 = recursivePow(5, evenCount, 1,MOD);
//         // We can place 0 2 4 6 8 that is 5 numbers at each even index

//         long long part2 = recursivePow(4, oddCount, 1,MOD);
//         // We can place 1 3 5 7 that is 4 numbers at each odd index

//         return (part1 * part2) % MOD;
//     }
// };