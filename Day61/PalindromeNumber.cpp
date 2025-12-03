// // Palindrome Number
// // Solved
// // Easy
// // Topics
// // premium lock icon
// // Companies
// // Hint
// // Given an integer x, return true if x is a palindrome, and false otherwise.

// // Example 1:

// // Input: x = 121
// // Output: true
// // Explanation: 121 reads as 121 from left to right and from right to left.
// // Example 2:

// // Input: x = -121
// // Output: false
// // Explanation: From left to right, it reads -121. From right to left, it
// becomes 121-. Therefore it is not a palindrome.
// // Example 3:

// // Input: x = 10
// // Output: false
// // Explanation: Reads 01 from right to left. Therefore it is not a
// palindrome.

// // Constraints:

// // -231 <= x <= 231 - 1

// // Follow up: Could you solve it without converting the integer to a string?

// string str = to_string(num);

// class Solution {
// public:
//     bool isPalindrome(int x) {
//         long reversedNumber = 0;
//         int backupX = x;
//         while(x>0){
//             int mod = x%10;
//             reversedNumber = reversedNumber*10+mod;
//             x = x/10;
//         }
//         return reversedNumber == backupX;
//     }
// };