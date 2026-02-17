// // Minimum Window Subsequence
// // Subscribe to TUF+

// // Hints
// // Company
// // ﻿Given strings s1 and s2, return the minimum contiguous substring part
// of
// // s1, so that s2 is a subsequence of the part.

// // If there is no such window in s1 that covers all characters in s2, return
// the
// // empty string "". If there are multiple such minimum-length windows, return
// // the one with the left-most starting index.

// // Example 1

// // Input: s1 = "abcdebdde", s2 = "bde"

// // Output: "bcde"

// // Explanation:

// // "bcde" is the answer because it occurs before "bdde" which has the same
// // length.

// // "deb" is not a smaller window because the elements of s2 in the window
// must
// // occur in order.

// // Example 2

// // Input: s1 = "jmeqsiwvaovvnbstl", s2 = "u"

// // Output: ""

// // Constraints

// // 1 <= s1.length <= 2 * 104
// // 1 <= s2.length <= 100
// // s1 and s2 consist of lowercase English letters.

// class Solution {
// public:
//     string minWindow(string s1, string s2) {

//         int n = s1.size();
//         int m = s2.size();

//         int minLen = INT_MAX;
//         int start = -1;
//         for(int i = 0; i < n; i++) {
//             if(s1[i]==s2[0]){
//                 int j=0;
//                 int k = i;
//                 while(k<n && j<m){
//                     if(s1[k]==s2[j]){
//                         j++;
//                     }
//                     k++;
//                 }
//                 // subsequence Found
//                 if(j==m){
//                     int end = k-1;

//                     // Now Backward Shrink
//                     j = m-1;
//                     k = end;

//                     while(j >= 0) {
//                         if(s1[k] == s2[j])
//                         {    j--;
//                         }
//                         k--;
//                     }
//                     k++;

//                     int windowStart = k;
//                     int len = end - windowStart + 1;

//                     if(len < minLen) {
//                         minLen = len;
//                         start = windowStart;
//                     }

//                     // move i to next possible start
//                     i = windowStart;

//                 }
//             }
//         }

//                 return start == -1 ? "" : s1.substr(start, minLen);

//     }
// };
