// // 1081. Smallest Subsequence of Distinct Characters
// // Solved
// // Medium
// // Topics
// // premium lock icon
// // Companies
// // Hint
// // Given a string s, return the lexicographically smallest subsequence of s
// that
// // contains all the distinct characters of s exactly once.

// // Example 1:

// // Input: s = "bcabc"
// // Output: "abc"
// // Example 2:

// // Input: s = "cbacdcbc"
// // Output: "acdb"

// // Constraints:

// // 1 <= s.length <= 1000
// // s consists of lowercase English letters.

// // Note: This question is the same as 316:
// // https://leetcode.com/problems/remove-duplicate-letters/

// class Solution {
// public:
//     string smallestSubsequence(string s) {
//         // Get Last occurance of each character
//         map<char, int> lastCharOccurance;
//         int n = s.size();
//         for (int i = 0; i < n; i++) {
//             lastCharOccurance[s[i]] = i;
//         }
//         stack<char> st;
//         map<char, bool> visited;
//         for (int i = 0; i < n; i++) {
//             if (visited[s[i]]) {
//                 continue;
//             }
//             while (!st.empty() && st.top() > s[i] &&
//                    lastCharOccurance[st.top()] > i) {
//                 visited[st.top()] = false;
//                 st.pop();
//             }
//             st.push(s[i]);
//             visited[s[i]] = true;
//         }
//         string ans;

//         while (!st.empty()) {
//             ans += st.top();
//             st.pop();
//         }

//         reverse(ans.begin(), ans.end());

//         return ans;
//     }
// };