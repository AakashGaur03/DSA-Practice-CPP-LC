// // Minimum Window Substring
// // Solved
// // Hard
// // Topics
// // premium lock icon
// // Companies
// // Hint
// // Given two strings s and t of lengths m and n respectively, return the
// minimum
// // window substring of s such that every character in t (including
// duplicates)
// // is included in the window. If there is no such substring, return the empty
// // string "".

// // The testcases will be generated such that the answer is unique.

// // Example 1:

// // Input: s = "ADOBECODEBANC", t = "ABC"
// // Output: "BANC"
// // Explanation: The minimum window substring "BANC" includes 'A', 'B', and
// 'C'
// // from string t. Example 2:

// // Input: s = "a", t = "a"
// // Output: "a"
// // Explanation: The entire string s is the minimum window.
// // Example 3:

// // Input: s = "a", t = "aa"
// // Output: ""
// // Explanation: Both 'a's from t must be included in the window.
// // Since the largest window of s only has one 'a', return empty string.

// class Solution {
// public:
//     string minWindow(string s, string t) {
//         int tSize = t.size();
//         int sSize = s.size();
//         int left = 0;
//         int right = 0;
//         int cnt = 0;
//         int minLen = INT_MAX;
//         int startIdx = -1;
//         vector<int> hashMap(256, 0);

//         for (int i = 0; i < tSize; i++) {
//             hashMap[t[i]]++;
//         }

//         while (right < sSize) {
//             if (hashMap[s[right]] > 0) {
//                 cnt++;
//             }
//             hashMap[s[right]]--;
//             while (cnt == tSize) {
//                 if ((right - left + 1) < minLen) {
//                     minLen = right - left + 1;
//                     startIdx = left;
//                 }
//                 // We will try to also reduce the size
//                 hashMap[s[left]]++;
//                 if (hashMap[s[left]] > 0) {
//                     cnt--;
//                 }
//                 left++;
//             }
//             right++;
//         }
//         if (startIdx == -1) {
//             return "";
//         }
//         return s.substr(startIdx, minLen);
//     }
// };