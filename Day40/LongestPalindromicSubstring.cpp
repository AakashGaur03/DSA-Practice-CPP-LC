// // Longest Palindromic Substring
// // Solved
// // Medium
// // Topics
// // premium lock icon
// // Companies
// // Hint
// // Given a string s, return the longest palindromic substring in s.

// // Example 1:

// // Input: s = "babad"
// // Output: "bab"
// // Explanation: "aba" is also a valid answer.
// // Example 2:

// // Input: s = "cbbd"
// // Output: "bb"

// // Constraints:

// // 1 <= s.length <= 1000
// // s consist of only digits and English letters.

// class Solution {
// public:
// bool isPalindrome(string &s, int left, int right) {
//     while (left < right) {
//         if (s[left] != s[right]) return false;
//         left++;
//         right--;
//     }
//     return true;
// }

//     string longestPalindrome(string s) {
//         int n= s.size();
//         int start = 0;
//         int maxLen = 0;
//         for(int i = 0;i<n;i++){
//             for(int j=i;j<n;j++){
//                 if(isPalindrome(s,i,j)){
//                     int len = j - i +1;
//                     if(len>maxLen){
//                         start = i;
//                         maxLen = len;
//                     }
//                 }

//             }
//         }
//         return s.substr(start,maxLen);
//     }
// };