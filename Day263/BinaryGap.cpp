// // Binary Gap
// // Easy
// // Topics
// // premium lock icon
// // Companies
// // Given a positive integer n, find and return the longest distance between
// any
// // two adjacent 1's in the binary representation of n. If there are no two
// // adjacent 1's, return 0.

// // Two 1's are adjacent if there are only 0's separating them (possibly no
// 0's).
// // The distance between two 1's is the absolute difference between their bit
// // positions. For example, the two 1's in "1001" have a distance of 3.

// // Example 1:

// // Input: n = 22
// // Output: 2
// // Explanation: 22 in binary is "10110".
// // The first adjacent pair of 1's is "10110" with a distance of 2.
// // The second adjacent pair of 1's is "10110" with a distance of 1.
// // The answer is the largest of these two distances, which is 2.
// // Note that "10110" is not a valid pair since there is a 1 separating the
// two
// // 1's underlined. Example 2:

// // Input: n = 8
// // Output: 0
// // Explanation: 8 in binary is "1000".
// // There are not any adjacent pairs of 1's in the binary representation of 8,
// so
// // we return 0. Example 3:

// // Input: n = 5
// // Output: 2
// // Explanation: 5 in binary is "101".

// // Constraints:

// // 1 <= n <= 109

// class Solution {
// public:
//     int countGap(string s) {
//         int prev = -1;
//         int res = 0;

//         for (int i = 0; i < s.size(); i++) {
//             if (s[i] == '1') {
//                 if (prev != -1) {
//                     res = max(res, i - prev);
//                 }
//                 prev = i;
//             }
//         }
//         return res;
//     }

//     string numberToBinary(int n) {
//         if (n == 0)
//             return "0";

//         string binaryVal = "";

//         while (n > 0) {
//             binaryVal += (n % 2) + '0';
//             n /= 2;
//         }
//         reverse(binaryVal.begin(), binaryVal.end());
//         return binaryVal;
//     }
//     int binaryGap(int n) {
//         string s = numberToBinary(n);
//         int res = countGap(s);

//         return res;
//     }
// };