// // Sort Characters By Frequency
// // Solved
// // Medium
// // Topics
// // premium lock icon
// // Companies
// // Given a string s, sort it in decreasing order based on the frequency of
// the
// // characters. The frequency of a character is the number of times it appears
// in
// // the string.

// // Return the sorted string. If there are multiple answers, return any of
// them.

// // Example 1:

// // Input: s = "tree"
// // Output: "eert"
// // Explanation: 'e' appears twice while 'r' and 't' both appear once.
// // So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a
// valid
// // answer. Example 2:

// // Input: s = "cccaaa"
// // Output: "aaaccc"
// // Explanation: Both 'c' and 'a' appear three times, so both "cccaaa" and
// // "aaaccc" are valid answers. Note that "cacaca" is incorrect, as the same
// // characters must be together. Example 3:

// // Input: s = "Aabb"
// // Output: "bbAa"
// // Explanation: "bbaA" is also a valid answer, but "Aabb" is incorrect.
// // Note that 'A' and 'a' are treated as two different characters.

// class Solution {
// public:
//     string frequencySort(string s) {
//         // TC O(n log k)
//         // SC O(n)
//         unordered_map<char,int> mpp;

//         for(int i=0;i<s.size();i++){
//             mpp[s[i]]++;
//         }

//         // Now we will use Priority Queue to store highest value at top
//         priority_queue<pair<int,char>> pq;
//         for(auto entry: mpp){
//             pq.push({entry.second,entry.first});
//         }

//         string res;
//         while(!pq.empty()){
//             auto [count, ch] = pq.top();
//             pq.pop();
//             res +=string(count,ch);
//         }
//         return res;
//     }
// };