// // Sum of Subarray Minimums
// // Solved
// // Medium
// // Topics
// // premium lock icon
// // Companies
// // Given an array of integers arr, find the sum of min(b), where b ranges
// over
// // every (contiguous) subarray of arr. Since the answer may be large, return
// the
// // answer modulo 109 + 7.

// // Example 1:

// // Input: arr = [3,1,2,4]
// // Output: 17
// // Explanation:
// // Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4],
// // [3,1,2,4]. Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1. Sum is 17. Example
// 2:

// // Input: arr = [11,81,94,43,3]
// // Output: 444

// class Solution {
// public:
//     vector<int> findNSE(vector<int>& arr) {
//         int n = arr.size();
//         stack<int> st;
//         vector<int> res(n);
//         for (int i = n - 1; i >= 0; i--) {
//             while (!st.empty() && arr[st.top()] >= arr[i]) {
//                 st.pop();
//             }
//             res[i] = st.empty() ? n : st.top();
//             st.push(i);
//         }
//         return res;
//     }
//     vector<int> prevSmallerOrEqual(vector<int>& arr) {
//         int n = arr.size();
//         stack<int> st;
//         vector<int> res(n);
//         for (int i = 0; i < n; i++) {
//             while (!st.empty() && arr[st.top()] > arr[i]) {
//                 st.pop();
//             }
//             res[i] = st.empty() ? -1 : st.top();
//             st.push(i);
//         }
//         return res;
//     }
//     int sumSubarrayMins(vector<int>& arr) {
//         int n = arr.size();
//         int total = 0;
//         int mod = int(1e9 + 7);
//         vector<int> nse = findNSE(arr);
//         vector<int> pse = prevSmallerOrEqual(arr);
//         for (int i = 0; i < n; i++) {
//             int left = i - pse[i];
//             int right = nse[i] - i;
//             total = (total + (1LL * arr[i] * left % mod * right % mod)) %
//             mod;

//         }
//         return total;
//     }
// };