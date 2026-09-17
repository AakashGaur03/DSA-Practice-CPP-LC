// // 520. Detect Capital
// // Solved
// // Easy
// // Topics
// // premium lock icon
// // Companies
// // We define the usage of capitals in a word to be right when one of the
// // following cases holds:

// // All letters in this word are capitals, like "USA".
// // All letters in this word are not capitals, like "leetcode".
// // Only the first letter in this word is capital, like "Google".
// // Given a string word, return true if the usage of capitals in it is right.

// // Example 1:

// // Input: word = "USA"
// // Output: true
// // Example 2:

// // Input: word = "FlaG"
// // Output: false

// // Constraints:

// // 1 <= word.length <= 100
// // word consists of lowercase and uppercase English letters.

// class Solution {
// public:
//     bool detectCapitalUse(string word) {
//         bool firstCapital = false;
//         bool secondCapital = false;
//         if (word.size() < 2) {
//             return true;
//         }
//         // 'A' = 65
//         // 'Z' = 90
//         // 'a' = 97
//         // 'z' = 122
//         if (word[0] < 'a') {
//             firstCapital = true;
//         }
//         if (word[1] < 'a') {
//             secondCapital = true;
//         }
//         for (int i = 1; i < word.size(); i++) {
//             if (firstCapital && secondCapital) {
//                 if (word[i] >= 'a') {
//                     return false;
//                 }
//             } else if (firstCapital) {
//                 if (word[i] < 'a') {
//                     return false;
//                 }
//                 // First is lowercase
//                 // → all remaining must be lowercase
//             } else {

//                 if (word[i] < 'a') {
//                     return false;
//                 }
//             }
//         }
//         return true;
//     }
// };