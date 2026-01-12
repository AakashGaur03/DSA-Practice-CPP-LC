// //  Sum of Number and Its Reverse
// // Solved
// // Medium
// // Topics
// // premium lock icon
// // Companies
// // Hint
// // Given a non-negative integer num, return true if num can be expressed as
// the
// // sum of any non-negative integer and its reverse, or false otherwise.

// // Example 1:

// // Input: num = 443
// // Output: true
// // Explanation: 172 + 271 = 443 so we return true.
// // Example 2:

// // Input: num = 63
// // Output: false
// // Explanation: 63 cannot be expressed as the sum of a non-negative integer
// and
// // its reverse so we return false. Example 3:

// // Input: num = 181
// // Output: true
// // Explanation: 140 + 041 = 181 so we return true. Note that when a number is
// // reversed, there may be leading zeros.

// class Solution {
// public:
// bool checkReverseAndOriginalResultToNum(int i, int target) {
//     string numString = to_string(i);
//     reverse(numString.begin(), numString.end());

//     int reversedNum = stoi(numString);
//     return (i + reversedNum == target);
// }
//     bool sumOfNumberAndReverse(int num) {
//         if (num == 0)
//             return true;

//         for (int i = 0; i <= num; i++) {
//             if(checkReverseAndOriginalResultToNum(i, num))return true;
//         }

//         return false;
//     }
// };