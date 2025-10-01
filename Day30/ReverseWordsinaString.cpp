// // Reverse Words in a String
// // Solved
// // Medium
// // Topics
// // premium lock icon
// // Companies
// // Given an input string s, reverse the order of the words.

// // A word is defined as a sequence of non-space characters. The words in s
// will be separated by at least one space.

// // Return a string of the words in reverse order concatenated by a single
// space.

// // Note that s may contain leading or trailing spaces or multiple spaces
// between two words. The returned string should only have a single space
// separating the words. Do not include any extra spaces.

// // Example 1:

// // Input: s = "the sky is blue"
// // Output: "blue is sky the"
// // Example 2:

// // Input: s = "  hello world  "
// // Output: "world hello"
// // Explanation: Your reversed string should not contain leading or trailing
// spaces.
// // Example 3:

// // Input: s = "a good   example"
// // Output: "example good a"
// // Explanation: You need to reduce multiple spaces between two words to a
// single space in the reversed string. class Solution { public:
//     string reverseWords(string s) {
//      int left = 0;
//      int right = s.size()-1;
//      string temp = "";
//      string ans = "";
//      while(left<=right){
//         char ch = s[left];
//         if(ch!= ' '){
//             temp+=ch;
//         } else if(ch == ' '){
//             if(temp !=""){
//                 if(ans!="") ans = temp+ " " + ans;
//                 else ans = temp;
//                 temp ="";
//             }
//         }
//         left++;
//      }
//      if(temp!=""){
//         if(temp !=""){
//             if(ans!="") ans = temp + " " + ans;
//             else ans = temp;
//         }
//      }
//      return ans;
//     }
// };

// //  string reverseWords(string s) {
// //         stack<string> st;
// //         string str="";
// //         string ans="";
// //       for(int i=0;i<s.size();i++){
// //         if(s[i]==' '){
// //              if (!str.empty()) {
// //             st.push(str);
// //             str="";
// //             }
// //         }else{
// //             str+=s[i]; // build the word
// //         }
// //       }
// //       if (!str.empty()) st.push(str); // Pushes Last

// //       while(st.size()!=1){
// //         ans+=st.top() +" ";
// //         st.pop();
// //       }
// //       ans+=st.top();
// //       return ans;
// //     }