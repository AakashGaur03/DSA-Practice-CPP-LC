// // Reverse Vowels of a String
// // Easy
// // Topics
// // premium lock icon
// // Companies
// // Given a string s, reverse only all the vowels in the string and return it.

// // The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both
// lower
// // and upper cases, more than once.

// // Example 1:

// // Input: s = "IceCreAm"

// // Output: "AceCreIm"

// // Explanation:

// // The vowels in s are ['I', 'e', 'e', 'A']. On reversing the vowels, s
// becomes
// // "AceCreIm".

// // Example 2:

// // Input: s = "leetcode"

// // Output: "leotcede"

// // Constraints:

// // 1 <= s.length <= 3 * 105
// // s consist of printable ASCII characters.

// class Solution {
// public:
//     bool isVowel(char c) {
//         return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
//                c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
//     }

//     string reverseVowels(string s) {
//         int start = 0;
//         int last = s.size() - 1;

//         while (start < last) {
//             if (!isVowel(s[start])) {
//                 start++;
//             } else if (!isVowel(s[last])) {
//                 last--;
//             } else {
//                 swap(s[start], s[last]);
//                 start++;
//                 last--;
//             }
//         }
//         return s;
//     }
// };