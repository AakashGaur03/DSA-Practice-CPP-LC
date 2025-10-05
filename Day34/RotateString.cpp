// // Rotate String
// // Solved
// // Easy
// // Topics
// // premium lock icon
// // Companies
// // Given two strings s and goal, return true if and only if s can become goal
// after some number of shifts on s.

// // A shift on s consists of moving the leftmost character of s to the
// rightmost position.

// // For example, if s = "abcde", then it will be "bcdea" after one shift.

// // Example 1:

// // Input: s = "abcde", goal = "cdeab"
// // Output: true
// // Example 2:

// // Input: s = "abcde", goal = "abced"
// // Output: false

// // Constraints:

// // 1 <= s.length, goal.length <= 100
// // s and goal consist of lowercase English letters.

// class Solution {
// public:
//     bool rotateString(string s, string goal) {
//         if(s.size()!=goal.size()) return false;
//         string doubled = s+s;

//         return doubled.find(goal) != string::npos;
//         // string::npos is a special constant in C++ that represents
//         // “no position” or “not found”.
//         // It’s used as a return value by string functions like .find(),
//         // to indicate that the searched substring does not exist.
//     }
// };

//     // bool rotateString(string s, string goal) {
//     //     // TC O(N^2)
//     //     if(s.size()!=goal.size()) return false;
//     //     int size = s.size();
//     //     for(int start=0;start<size;start++){
//     //         if(goal[start] == s[0]){
//     //         int j=start;
//     //         bool isMatch = true;
//     //             for(int i=0;i<size;i++){
//     //                 if(s[i]!= goal[j]){
//     //                     isMatch = false;
//     //                     break;
//     //                 }
//     //                 // move `j` forward, circularly
//     //                 j = (j + 1) % size;
//     //                 // (% n ensures if we reach end, we wrap back to 0)
//     //             }
//     //             if(isMatch) return true;
//     //         }
//     //     }
//     //     return false;
//     // }