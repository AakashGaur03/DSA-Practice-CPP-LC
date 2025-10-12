// //  Sum of Beauty of All Substrings
// // Solved
// // Medium
// // Topics
// // premium lock icon
// // Companies
// // Hint
// // The beauty of a string is the difference in frequencies between the most
// frequent and least frequent characters.

// // For example, the beauty of "abaacc" is 3 - 1 = 2.
// // Given a string s, return the sum of beauty of all of its substrings.

// // Example 1:

// // Input: s = "aabcb"
// // Output: 5
// // Explanation: The substrings with non-zero beauty are
// ["aab","aabc","aabcb","abcb","bcb"], each with beauty equal to 1.
// // Example 2:

// // Input: s = "aabcbaa"
// // Output: 17

// // Constraints:

// // 1 <= s.length <= 500
// // s consists of only lowercase English letters.

// class Solution {
// public:
//     int beautySum(string s) {
//         // TC O(2N)
//         // SC O(1)

//         // Outer loop: O(n) (for each starting index)
//         // Inner loop: O(n) (for each ending index)
//         // Computing max and min for frequencies: O(26) in the worst case
//         (since
//         // only lowercase letters), O(n^2 * 26) ≈ O(n^2) because 26 is
//         constant.
//         // Space Complexity:
//         // Frequency map uses at most 26 characters → O(26) = O(1).
//         int n = s.size();
//         int sum = 0;
//         for (int i = 0; i < n; i++) {
//             unordered_map<char, int> mpp;
//             // store frequency of each character
//             for (int j = i; j < n; j++) {
//                 // get all subsstrings frequency
//                 mpp[s[j]]++;
//                 int maxi = INT_MIN;
//                 int mini = INT_MAX;
//                 // Iterate over map and calcuate max and min
//                 for (auto it : mpp) {
//                     maxi = max(maxi, it.second);
//                     mini = min(mini, it.second);
//                 }
//                 // calculate sum of beauty
//                 sum += (maxi - mini);
//             }
//         }
//         return sum;
//     }
// };