// // 301. Remove Invalid Parentheses
// // Solved
// // Hard
// // Topics
// // premium lock icon
// // Companies
// // Hint
// // Given a string s that contains parentheses and letters, remove the minimum
// // number of invalid parentheses to make the input string valid.

// // Return a list of unique strings that are valid with the minimum number of
// // removals. You may return the answer in any order.

// // Example 1:

// // Input: s = "()())()"
// // Output: ["(())()","()()()"]
// // Example 2:

// // Input: s = "(a)())()"
// // Output: ["(a())()","(a)()()"]
// // Example 3:

// // Input: s = ")("
// // Output: [""]

// // Constraints:

// // 1 <= s.length <= 25
// // s consists of lowercase English letters and parentheses '(' and ')'.
// // There will be at most 20 parentheses in s.

// class Solution {
// public:
//     bool isValid(string s) {
//         int count = 0;

//         for (char ch : s) {

//             if (ch == '(') {
//                 count++;
//             } else if (ch == ')') {
//                 count--;

//                 if (count < 0) {
//                     return false;
//                 }
//             }
//         }

//         return count == 0;
//     }

//     void recursionSol(int i, int numberOfRemoval, string& s, int& minRemoval,
//                       vector<string>& ans) {
//         if (i == s.size()) {
//             if (isValid(s)) {
//                 if (numberOfRemoval < minRemoval) {
//                     minRemoval = numberOfRemoval;
//                     ans.clear();
//                     ans.push_back(s);
//                 } else if (numberOfRemoval == minRemoval) {
//                     ans.push_back(s);
//                 }
//             }
//             return;
//         }

//         recursionSol(i + 1, numberOfRemoval, s, minRemoval, ans);

//         char ch = s[i];
//         s.erase(i, 1);
//         recursionSol(i, numberOfRemoval + 1, s, minRemoval, ans);
//         s.insert(i, 1, ch);
//     }

//     void recursionSol2(int i, int leftRemove, int rightRemove, int openCount,
//                        string& s, string& currentString, vector<string>& ans)
//                        {

//         if (i == s.size()) {

//             if (leftRemove == 0 && rightRemove == 0 && openCount == 0) {

//                 ans.push_back(currentString);
//             }

//             return;
//         }

//         if (s[i] == '(') {
//             // Delete '('
//             if (leftRemove > 0) {
//                 recursionSol2(i + 1, leftRemove - 1, rightRemove, openCount,
//                 s,
//                               currentString, ans);
//             }
//             // Keep '('
//             currentString.push_back('(');
//             recursionSol2(i + 1, leftRemove, rightRemove, openCount + 1, s,
//                           currentString, ans);
//             currentString.pop_back();

//             // Current character is ')'
//         } else if (s[i] == ')') {

//             // Delete ')'
//             if (rightRemove > 0) {
//                 recursionSol2(i + 1, leftRemove, rightRemove - 1, openCount,
//                 s,
//                               currentString, ans);
//             }

//             // Keep ')' only if there is '(' to close
//             if (openCount > 0) {
//                 currentString.push_back(')');
//                 recursionSol2(i + 1, leftRemove, rightRemove, openCount - 1,
//                 s,
//                               currentString, ans);

//                 currentString.pop_back();
//             }
//         }
//         // Normal character
//         else {

//             currentString.push_back(s[i]);

//             recursionSol2(i + 1, leftRemove, rightRemove, openCount, s,
//                           currentString, ans);

//             currentString.pop_back();
//         }
//     }

//     vector<string> removeInvalidParentheses(string s) {

//         vector<string> ans;

//         int leftRemove = 0;
//         int rightRemove = 0;

//         for (char ch : s) {
//             if (ch == '(') {
//                 leftRemove++;
//             } else if (ch == ')') {
//                 if (leftRemove > 0) {
//                     leftRemove--;
//                 } else {
//                     rightRemove++;
//                 }
//             }
//         }

//         string currentString = "";

//         recursionSol2(0, leftRemove, rightRemove, 0, s, currentString, ans);

//         sort(ans.begin(), ans.end());

//         ans.erase(unique(ans.begin(), ans.end()), ans.end());

//         return ans;

//         // vector<string> ans;
//         // int minRemoval = INT_MAX;
//         // recursionSol(0, 0, s, minRemoval, ans); // MLE
//         // sort(ans.begin(), ans.end());
//         // ans.erase(unique(ans.begin(), ans.end()), ans.end());
//         // return ans;
//     }
// };