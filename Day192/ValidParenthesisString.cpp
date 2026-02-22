// // Valid Parenthesis String
// // Solved
// // Medium
// // Topics
// // premium lock icon
// // Companies
// // Hint
// // Given a string s containing only three types of characters: '(', ')' and
// '*',
// // return true if s is valid.

// // The following rules define a valid string:

// // Any left parenthesis '(' must have a corresponding right parenthesis ')'.
// // Any right parenthesis ')' must have a corresponding left parenthesis '('.
// // Left parenthesis '(' must go before the corresponding right parenthesis
// ')'.
// // '*' could be treated as a single right parenthesis ')' or a single left
// // parenthesis '(' or an empty string "".
// // Example 1:

// // Input: s = "()"
// // Output: true
// // Example 2:

// // Input: s = "(*)"
// // Output: true
// // Example 3:

// // Input: s = "(*))"
// // Output: true

// // Constraints:

// // 1 <= s.length <= 100
// // s[i] is '(', ')' or '*'.

// class Solution {
// public:
//     bool checkValidString(string s) {
//         int size = s.size();
//         int min = 0;
//         int max = 0;

//         for (int i = 0; i < size; i++) {
//             if (s[i] == '(') {
//                 min++;
//                 max++;
//             } else if (s[i] == ')') {
//                 min--;
//                 max--;

//             } else {
//                 min--;
//                 max++;
//             }
//             if (min < 0)
//                 min = 0;
//             if (max < 0)
//                 return false;
//         }

//         return (min == 0);
//     }
// };