// // Generate Parentheses
// // Solved
// // Medium
// // Topics
// // premium lock icon
// // Companies
// // Given n pairs of parentheses, write a function to generate all
// combinations
// // of well-formed parentheses.

// // Example 1:

// // Input: n = 3
// // Output: ["((()))","(()())","(())()","()(())","()()()"]
// // Example 2:

// // Input: n = 1
// // Output: ["()"]

// // Constraints:

// // 1 <= n <= 8

// class Solution {
// public:
//     void recursiveAllParenthesis(int open, int close, string str, int n,
//                                  vector<string>& arr) {

//         if (str.size() == 2 * n) {
//             arr.push_back(str);
//             return;
//         }
//         if (open < n) {
//             recursiveAllParenthesis(open + 1, close, str + "(", n, arr);
//         }
//         if (close < open) {
//             recursiveAllParenthesis(open, close + 1, str + ")", n, arr);
//         }
//     }

//     void generateAllParenthesis(int n, vector<string>& arr) {

//         recursiveAllParenthesis(0, 0, "", n, arr);
//     }
//     vector<string> generateParenthesis(int n) {
//         vector<string> arr;
//         generateAllParenthesis(n, arr);
//         return arr;
//     }
// };

// // bool validParenthesis(string str) {
// //     int cnt = 0;
// //     for (int i = 0; i < str.size(); i++) {
// //         if (str[i] == '(') {
// //             cnt++;
// //         }
// //         if (cnt > 0 && str[i] == ')') {
// //             cnt--;
// //         } else if (cnt == 0 && str[i] == ')') {
// //             return false;
// //         }
// //     }

// //     return cnt == 0;
// // }

// // void recursiveAllParenthesis(int index, string str, int n,
// //                              vector<string>& arr) {
// //     if (index == 2 * n) {
// //         if (validParenthesis(str)) {
// //             arr.push_back(str);
// //         }
// //         return;
// //     }

// //     recursiveAllParenthesis(index + 1, str + "(", n, arr);
// //     recursiveAllParenthesis(index + 1, str + ")", n, arr);
// // }

// // void generateAllParenthesis(int n, vector<string>& arr) {

// //     recursiveAllParenthesis(0, "", n, arr);
// // }