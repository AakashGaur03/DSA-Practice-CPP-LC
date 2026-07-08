// // 1356. Sort Integers by The Number of 1 Bits
// // Solved
// // Easy
// // Topics
// // premium lock icon
// // Companies
// // Hint
// // You are given an integer array arr. Sort the integers in the array in
// // ascending order by the number of 1's in their binary representation and in
// // case of two or more integers have the same number of 1's you have to sort
// // them in ascending order.

// // Return the array after sorting it.

// // Example 1:

// // Input: arr = [0,1,2,3,4,5,6,7,8]
// // Output: [0,1,2,4,8,3,5,6,7]
// // Explantion: [0] is the only integer with 0 bits.
// // [1,2,4,8] all have 1 bit.
// // [3,5,6] have 2 bits.
// // [7] has 3 bits.
// // The sorted array by bits is [0,1,2,4,8,3,5,6,7]
// // Example 2:

// // Input: arr = [1024,512,256,128,64,32,16,8,4,2,1]
// // Output: [1,2,4,8,16,32,64,128,256,512,1024]
// // Explantion: All integers have 1 bit in the binary representation, you
// should
// // just sort them in ascending order.

// // Constraints:

// // 1 <= arr.length <= 500
// // 0 <= arr[i] <= 104

// class Solution {
// public:
//     vector<int> sortByBits(vector<int>& arr) {
//         vector<int> ans;
//         vector<pair<int, int>> temp;
//         for (int i = 0; i < arr.size(); i++) {
//             int num = arr[i];
//             int cnt = 0;

//             while (num > 0) {
//                 cnt += num & 1;
//                 num >>= 1;
//             }
//             temp.push_back({cnt, arr[i]});
//         }
//         sort(temp.begin(), temp.end());

//         for (auto &it : temp) {
//             ans.push_back(it.second);
//         }
//         return ans;
//     }
// };

// // // Number of Set Bits
// // int cnt = 0;
// // while (n > 0) {
// //     cnt += n & 1; // n & 1 adds 1 if the last bit is set.
// //     n = n >> 1;   // DIVIDE BY 2
// // }