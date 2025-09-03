// 1071. Greatest Common Divisor of Strings
// Solved
// Easy
// Topics
// premium lock icon
// Companies
// Hint
// For two strings s and t, we say "t divides s" if and only if s = t + t + t +
// ... + t + t (i.e., t is concatenated with itself one or more times).

// Given two strings str1 and str2, return the largest string x such that x
// divides both str1 and str2.

// Example 1:

// Input: str1 = "ABCABC", str2 = "ABC"
// Output: "ABC"
// Example 2:

// Input: str1 = "ABABAB", str2 = "ABAB"
// Output: "AB"
// Example 3:

// Input: str1 = "LEET", str2 = "CODE"
// Output: ""

// class Solution {
// public:

//     int gcdLen(int num1,int num2){
//         while(num1>0 && num2>0){
//             if(num1>num2){
//                 num1 = num1 % num2;
//             }else{
//                 num2 = num2 % num1;
//             }
//         }
//         if(num1 == 0) return num2;
//         return num1;
//     }
//     string gcdOfStrings(string str1, string str2) {
//         if(str1+str2 != str2+str1 ) return "";
//         int gcdRes = gcdLen(str1.size(),str2.size());
//         string ans = "";
//         for(int i = 0;i<gcdRes;i++){
//             ans+=str1[i];
//         }
//         return ans;
//     }
// };