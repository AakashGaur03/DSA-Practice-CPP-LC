// // Palindrome Partitioning
// // Solved
// // Medium
// // Topics
// // premium lock icon
// // Companies
// // Given a string s, partition s such that every substring of the partition
// is a
// // palindrome. Return all possible palindrome partitioning of s.

// // Example 1:

// // Input: s = "aab"
// // Output: [["a","a","b"],["aa","b"]]
// // Example 2:

// // Input: s = "a"
// // Output: [["a"]]

// // Constraints:

// // 1 <= s.length <= 16
// // s contains only lowercase English letters.

// class Solution {
// public:
//     bool isPalindrome(string s, int start, int end) {

//         while (start <= end) {
//             if (s[start++] != s[end--])
//                 return false;
//         }

//         return true;
//     }
//     void solvePalindromicSubstring(int n, string s, vector<string>& ds,
//                                    vector<vector<string>>& ans) {
//         if (n == s.size()) {
//             ans.push_back(ds);
//             return;
//         }
//         for (int i = n; i < s.size(); i++) {
//             if (isPalindrome(s, n, i)) {
//                 ds.push_back(s.substr(n, i - n + 1));
//                 solvePalindromicSubstring(i + 1, s, ds, ans);
//                 ds.pop_back();
//             }
//         }
//     };
//     vector<vector<string>> partition(string s) {
//         vector<vector<string>> ans;
//         vector<string> ds;
//         solvePalindromicSubstring(0, s, ds, ans);
//         return ans;
//     }
// };