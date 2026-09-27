// // 1190. Reverse Substrings Between Each Pair of Parentheses
// // Solved
// // Medium
// // Topics
// // premium lock icon
// // Companies
// // Hint
// // You are given a string s that consists of lower case English letters and
// // brackets.

// // Reverse the strings in each pair of matching parentheses, starting from
// the
// // innermost one.

// // Your result should not contain any brackets.

// // Example 1:

// // Input: s = "(abcd)"
// // Output: "dcba"
// // Example 2:

// // Input: s = "(u(love)i)"
// // Output: "iloveu"
// // Explanation: The substring "love" is reversed first, then the whole string
// is
// // reversed. Example 3:

// // Input: s = "(ed(et(oc))el)"
// // Output: "leetcode"
// // Explanation: First, we reverse the substring "oc", then "etco", and
// finally,
// // the whole string.

// // Constraints:

// // 1 <= s.length <= 2000
// // s only contains lower case English characters and parentheses.
// // It is guaranteed that all parentheses are balanced.

// class Solution {
// public:
//     string reverseParentheses(string s) {
//         int n = s.size();
//         vector<int> pair(n);
//         stack<int> st;

//         for(int i=0;i<n;i++){
//             if(s[i]=='('){
//                 st.push(i);
//             }else if(s[i]==')'){
//                 int open = st.top();
//                 st.pop();

//                 pair[open] = i;
//                 pair[i] = open;
//             }
//         }

//         string ans;
//         int step = 1;

//         for(int i=0;i>=0 && i<n;i+=step){
//             if(islower(s[i])){
//                 ans+=s[i];
//             }
//             else{
//                 i = pair[i];
//                 step = -step;
//             }
//         }
//         return ans;
//     }
// };