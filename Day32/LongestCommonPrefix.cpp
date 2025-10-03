// // 14. Longest Common Prefix
// // Solved
// // Easy
// // Topics
// // premium lock icon
// // Companies
// // Write a function to find the longest common prefix string amongst an array
// of strings.

// // If there is no common prefix, return an empty string "".

// // Example 1:

// // Input: strs = ["flower","flow","flight"]
// // Output: "fl"
// // Example 2:

// // Input: strs = ["dog","racecar","car"]
// // Output: ""
// // Explanation: There is no common prefix among the input strings.

// // Constraints:

// // 1 <= strs.length <= 200
// // 0 <= strs[i].length <= 200
// // strs[i] consists of only lowercase English letters if it is non-empty.

// #include <bits/stdc++.h>
// class Solution {
// public:
//     string longestCommonPrefix(vector<string>& strs) {
//         if(strs.empty()) return "";
//         sort(strs.begin(),strs.end());
//         string ans ="";
//         // After sorting we can compare first and last strings
//         string first = strs[0];
//         string last = strs[strs.size()-1];
//         int minimalLength = min(first.size(),last.size());
//         for(int i = 0;i<minimalLength;i++){
//             if(first[i]==last[i]){
//                 ans+=first[i];
//             }else{
//                 break;
//             }
//         }
//         return ans;
//     }
// };