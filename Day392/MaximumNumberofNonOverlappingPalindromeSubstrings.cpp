// // 2472. Maximum Number of Non-overlapping Palindrome Substrings
// // Solved
// // Hard
// // Topics
// // premium lock icon
// // Companies
// // Hint
// // You are given a string s and a positive integer k.

// // Select a set of non-overlapping substrings from the string s that satisfy
// the
// // following conditions:

// // The length of each substring is at least k.
// // Each substring is a palindrome.
// // Return the maximum number of substrings in an optimal selection.

// // A substring is a contiguous sequence of characters within a string.

// // Example 1:

// // Input: s = "abaccdbbd", k = 3
// // Output: 2
// // Explanation: We can select the substrings underlined in s = "abaccdbbd".
// Both
// // "aba" and "dbbd" are palindromes and have a length of at least k = 3. It
// can
// // be shown that we cannot find a selection with more than two valid
// substrings.
// // Example 2:

// // Input: s = "adbcda", k = 2
// // Output: 0
// // Explanation: There is no palindrome substring of length at least 2 in the
// // string.

// // Constraints:

// // 1 <= k <= s.length <= 2000
// // s consists of lowercase English letters.

// class Solution {
// public:
//     int recursionSol(int ind, string& s, int k,
//                      vector<vector<bool>>& palindrome) {

//         int n = s.size();
//         if (ind >= n) {
//             return 0;
//         }

//         int notTake = recursionSol(ind + 1, s, k, palindrome);

//         int take = 0;

//         // Try every substring starting from ind
//         for (int end = ind; end < n; end++) {
//             int len = end - ind + 1;
//             if (len >= k && palindrome[ind][end]) {
//                 take = max(take, 1 + recursionSol(end + 1, s, k,
//                 palindrome));
//             }
//         }
//         return max(take, notTake);
//     }
//     int memoizationSol(int ind, string& s, int k,
//                        vector<vector<bool>>& palindrome, vector<int>& dp) {

//         int n = s.size();
//         if (ind >= n) {
//             return 0;
//         }

//         if (dp[ind] != -1) {
//             return dp[ind];
//         }

//         int notTake = memoizationSol(ind + 1, s, k, palindrome, dp);

//         int take = 0;

//         // Try every substring starting from ind
//         for (int end = ind; end < n; end++) {
//             int len = end - ind + 1;
//             if (len >= k && palindrome[ind][end]) {
//                 take = max(take,
//                            1 + memoizationSol(end + 1, s, k, palindrome,
//                            dp));
//             }
//         }
//         return dp[ind] = max(take, notTake);
//     }

//     int tabulationSol(string& s, int k,
//                   vector<vector<bool>>& palindrome) {

//     int n = s.size();

//     vector<int> dp(n + 1, 0);

//     for (int ind = n - 1; ind >= 0; ind--) {

//         int notTake = dp[ind + 1];

//         int take = 0;

//         for (int end = ind; end < n; end++) {

//             int len = end - ind + 1;

//             if (len >= k && palindrome[ind][end]) {

//                 take = max(
//                     take,
//                     1 + dp[end + 1]
//                 );
//             }
//         }

//         dp[ind] = max(take, notTake);
//     }

//     return dp[0];
// }

//     int maxPalindromes(string s, int k) {
//         int n = s.size();

//         vector<vector<bool>> palindrome(n, vector<bool>(n, false));

//         // Build palindrome table
//         for (int len = 1; len <= n; len++) {

//             for (int i = 0; i + len <= n; i++) {

//                 int j = i + len - 1;

//                 if (s[i] == s[j]) {

//                     if (len <= 2) {
//                         palindrome[i][j] = true;
//                     } else {
//                         palindrome[i][j] = palindrome[i + 1][j - 1];
//                     }
//                 }
//             }
//         }
//         vector<int> dp(n, -1);

//         // return recursionSol(0, s, k, palindrome);
//         // return memoizationSol(0, s, k, palindrome,dp);
//         return tabulationSol( s, k, palindrome);
//     }
// };