// // Longest Common Suffix Queries
// // Attempted
// // Hard
// // Topics
// // premium lock icon
// // Companies
// // Hint
// // You are given two arrays of strings wordsContainer and wordsQuery.

// // For each wordsQuery[i], you need to find a string from wordsContainer that
// // has the longest common suffix with wordsQuery[i]. If there are two or more
// // strings in wordsContainer that share the longest common suffix, find the
// // string that is the smallest in length. If there are two or more such
// strings
// // that have the same smallest length, find the one that occurred earlier in
// // wordsContainer.

// // Return an array of integers ans, where ans[i] is the index of the string
// in
// // wordsContainer that has the longest common suffix with wordsQuery[i].

// // Example 1:

// // Input: wordsContainer = ["abcd","bcd","xbcd"], wordsQuery =
// // ["cd","bcd","xyz"]

// // Output: [1,1,1]

// // Explanation:

// // Let's look at each wordsQuery[i] separately:

// // For wordsQuery[0] = "cd", strings from wordsContainer that share the
// longest
// // common suffix "cd" are at indices 0, 1, and 2. Among these, the answer is
// the
// // string at index 1 because it has the shortest length of 3. For
// wordsQuery[1]
// // = "bcd", strings from wordsContainer that share the longest common suffix
// // "bcd" are at indices 0, 1, and 2. Among these, the answer is the string at
// // index 1 because it has the shortest length of 3. For wordsQuery[2] =
// "xyz",
// // there is no string from wordsContainer that shares a common suffix. Hence
// the
// // longest common suffix is "", that is shared with strings at index 0, 1,
// // and 2. Among these, the answer is the string at index 1 because it has the
// // shortest length of 3. Example 2:

// // Input: wordsContainer = ["abcdefgh","poiuygh","ghghgh"], wordsQuery =
// // ["gh","acbfgh","acbfegh"]

// // Output: [2,0,2]

// // Explanation:

// // Let's look at each wordsQuery[i] separately:

// // For wordsQuery[0] = "gh", strings from wordsContainer that share the
// longest
// // common suffix "gh" are at indices 0, 1, and 2. Among these, the answer is
// the
// // string at index 2 because it has the shortest length of 6. For
// wordsQuery[1]
// // = "acbfgh", only the string at index 0 shares the longest common suffix
// // "fgh". Hence it is the answer, even though the string at index 2 is
// shorter.
// // For wordsQuery[2] = "acbfegh", strings from wordsContainer that share the
// // longest common suffix "gh" are at indices 0, 1, and 2. Among these, the
// // answer is the string at index 2 because it has the shortest length of 6.

// // Constraints:

// // 1 <= wordsContainer.length, wordsQuery.length <= 104
// // 1 <= wordsContainer[i].length <= 5 * 103
// // 1 <= wordsQuery[i].length <= 5 * 103
// // wordsContainer[i] consists only of lowercase English letters.
// // wordsQuery[i] consists only of lowercase English letters.
// // Sum of wordsContainer[i].length is at most 5 * 105.
// // Sum of wordsQuery[i].length is at most 5 * 105.

// TLE
// class Solution {
// public:
//     vector<int> stringIndices(vector<string>& wordsContainer,
//                               vector<string>& wordsQuery) {
//                                 // TC (O(Q * N * L))
//         vector<int> ans;

//         // Default index:
//         // smallest length word in container
//         int defaultIdx = 0;
//         // It will gives us Default Answer of same length or no length match
//         for (int i = 1; i < wordsContainer.size(); i++) {
//             if (wordsContainer[i].size() < wordsContainer[defaultIdx].size())
//             {
//                 defaultIdx = i;
//             }
//         }

//         for (string query : wordsQuery) {
//             int bestMatch = -1;
//             int bestLen = -1;
//             for (int j = 0; j < wordsContainer.size(); j++) {

//                 string stringFromQuery = query;
//                 string stringFromContainer = wordsContainer[j];

//                 reverse(stringFromQuery.begin(), stringFromQuery.end());
//                 reverse(stringFromContainer.begin(),
//                 stringFromContainer.end()); int common= 0; int sizeLoop =
//                     min(stringFromContainer.size(), stringFromQuery.size());

//                 for (int k = 0; k < sizeLoop; k++) {
//                     if (stringFromContainer[k] == stringFromQuery[k]) {
//                         common++;
//                     } else {
//                         break;
//                     }
//                 }

//                 if (common > bestLen) {
//                     bestLen = common;
//                     bestMatch = j;
//                 } else if (common == bestLen) {
//                     if (wordsContainer[j].size() <
//                         wordsContainer[bestMatch].size()) {

//                         bestMatch = j;
//                     } else if (wordsContainer[j].size() ==
//                                wordsContainer[bestMatch].size()) {

//                         if (j < bestMatch) {
//                             bestMatch = j;
//                         }
//                     }
//                 }
//             }
//             if (bestMatch == -1) {
//                 ans.push_back(defaultIdx);
//             } else {
//                 ans.push_back(bestMatch);
//             }
//         }
//         return ans;
//     }
// };