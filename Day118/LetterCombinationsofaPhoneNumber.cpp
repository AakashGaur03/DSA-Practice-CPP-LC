// //  Letter Combinations of a Phone Number
// // Solved
// // Medium
// // Topics
// // premium lock icon
// // Companies
// // Given a string containing digits from 2-9 inclusive, return all possible
// // letter combinations that the number could represent. Return the answer in
// any
// // order.

// // A mapping of digits to letters (just like on the telephone buttons) is
// given
// // below. Note that 1 does not map to any letters.

// // Example 1:

// // Input: digits = "23"
// // Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
// // Example 2:

// // Input: digits = "2"
// // Output: ["a","b","c"]

// class Solution {
// public:
//     void findLetterCombinations(int index, string& digits,
//                                 map<char, string>& mapping, string current,
//                                 vector<string>& res) {
//         if (index == digits.size()) {
//             res.push_back(current);
//             return;
//         }
//         string letters = mapping[digits[index]];

//         for (char ch : letters) {
//             findLetterCombinations(index + 1, digits, mapping, current + ch,
//                                    res);
//         }
//     }
//     vector<string> letterCombinations(string digits) {
//         if (digits.empty())
//             return {};
//         map<char, string> mapping;
//         mapping['2'] = "abc";
//         mapping['3'] = "def";
//         mapping['4'] = "ghi";
//         mapping['5'] = "jkl";
//         mapping['6'] = "mno";
//         mapping['7'] = "pqrs";
//         mapping['8'] = "tuv";
//         mapping['9'] = "wxyz";
//         vector<string> res;
//         findLetterCombinations(0, digits, mapping, "", res);
//         return res;
//     }
// };