// // Largest Rectangle in Histogram
// // Solved
// // Hard
// // Topics
// // premium lock icon
// // Companies
// // Given an array of integers heights representing the histogram's bar height
// // where the width of each bar is 1, return the area of the largest rectangle
// in
// // the histogram.

// // Example 1:

// // Input: heights = [2,1,5,6,2,3]
// // Output: 10
// // Explanation: The above is a histogram where width of each bar is 1.
// // The largest rectangle is shown in the red area, which has an area = 10
// units.
// // Example 2:

// // Input: heights = [2,4]
// // Output: 4

// class Solution {
// public:
//     int largestRectangleArea(vector<int>& heights) {
//         int size = heights.size();
//         stack<int> st;
//         int maxi = 0;
//         for (int i = 0; i < size; i++) {
//             while (!st.empty() && heights[st.top()] > heights[i]) {
//                 int element = st.top();
//                 st.pop();
//                 int nse = i;
//                 int pse = st.empty() ? -1 : st.top();

//             maxi = max(maxi, (heights[element]) * (nse - pse - 1));
//             }
//             st.push(i);
//         }

//         while (!st.empty()) {
//             int nse = size;
//             int element = st.top();
//             st.pop();
//             int pse = st.empty() ? -1 : st.top();
//             maxi = max(maxi, (heights[element]) * (nse - pse - 1));
//         }
//         return maxi;
//     }
// };