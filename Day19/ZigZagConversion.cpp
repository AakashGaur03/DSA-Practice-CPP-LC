// // // HARDEST ONE SO FAR

// //  Zigzag Conversion
// // Solved
// // Medium
// // Topics
// // premium lock icon
// // Companies
// // The string "PAYPALISHIRING" is written in a zigzag pattern on a given
// number of rows like this: (you may want to display this pattern in a fixed
// font for better legibility)

// // P   A   H   N
// // A P L S I I G
// // Y   I   R
// // And then read line by line: "PAHNAPLSIIGYIR"

// // Write the code that will take a string and make this conversion given a
// number of rows:

// // string convert(string s, int numRows);

// // Example 1:

// // Input: s = "PAYPALISHIRING", numRows = 3
// // Output: "PAHNAPLSIIGYIR"
// // Example 2:

// // Input: s = "PAYPALISHIRING", numRows = 4
// // Output: "PINALSIGYAHRPI"
// // Explanation:
// // P     I    N
// // A   L S  I G
// // Y A   H R
// // P     I
// // Example 3:

// // Input: s = "A", numRows = 1
// // Output: "A"

//  class Solution {
// public:
//     string convert(string s, int numRows) {
//          if(numRows == 1) return s;
//         vector<string> rows(numRows);
//         // array of strings
//         // rows = ["", "", "", ""]
//         string ans;
//         int currRow = 0;
//         bool isGoingDown = true;

//         // we are filling row here
//         for(char c: s){
//             rows[currRow]+=c;
//             if(currRow == 0) isGoingDown = true;
//             if(currRow == numRows-1) isGoingDown = false;
//             currRow+= (isGoingDown?1:-1);
//         }

//         for(auto rowStr: rows) ans+=rowStr;
//         return ans;
//     }
// };

// // |    /|    /|    /|
// // |  /  |  /  |  /  |
// // |/    |/    |/    |

// // With 2D array with visualization
// // TC O(n × numRows) which we are taking to fill the ans
// // SC O(n × numRows) — extra space for the matrix.
// //   string convert(string s, int numRows) {
// //         if(numRows == 1) return s;
// //         vector<vector<char>> arr(numRows,vector<char>(s.size(),' '));
// //         int lenS = s.size();
// //         int row = 0;
// //         int col = 0;
// //         bool isGoingDown = true;
// //         string ans;

// //         for(int traverseS = 0;traverseS<lenS;traverseS++){
// //             arr[row][col] = s[traverseS];
// //             if(row == 0) isGoingDown = true; // First Row
// //             if(row == numRows-1) isGoingDown = false; // Last row
// //             row+= (isGoingDown? 1 : -1);
// //             if(!isGoingDown) col++; // only for visualization
// //         }

// //         for (const auto& row : arr) {
// //             for (char val : row) {
// //                 if(val==' ')continue;
// //                 ans+=val;
// //             }
// //         }
// //     return ans;
// //     }