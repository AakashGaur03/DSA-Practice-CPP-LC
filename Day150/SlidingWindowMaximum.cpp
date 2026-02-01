// // Sliding Window Maximum
// // Solved
// // Hard
// // Topics
// // premium lock icon
// // Companies
// // Hint
// // You are given an array of integers nums, there is a sliding window of size
// k
// // which is moving from the very left of the array to the very right. You can
// // only see the k numbers in the window. Each time the sliding window moves
// // right by one position.

// // Return the max sliding window.

// // Example 1:

// // Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
// // Output: [3,3,5,5,6,7]
// // Explanation:
// // Window position                Max
// // ---------------               -----
// // [1  3  -1] -3  5  3  6  7       3
// //  1 [3  -1  -3] 5  3  6  7       3
// //  1  3 [-1  -3  5] 3  6  7       5
// //  1  3  -1 [-3  5  3] 6  7       5
// //  1  3  -1  -3 [5  3  6] 7       6
// //  1  3  -1  -3  5 [3  6  7]      7
// // Example 2:

// // Input: nums = [1], k = 1
// // Output: [1]

// class Solution {
// public:
//     vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//         // Monotonic Deque
//         int n = nums.size();
//         vector<int> ans;
//         deque<int> dq;

//         for (int i = 0; i < n; i++) {

//             // Remove elements which are OUTSIDE the current window
//             // Current window range is [i - k + 1, i]
//             // If an index at the front is <= i - k, it is no longer in
//             window if (!dq.empty() && dq.front() <= i - k) {
//                 dq.pop_front();
//             }

//             // Maintain decreasing order in deque
//             // Remove all elements from back which are smaller than current
//             // element Because they can never be the maximum for this or any
//             // future window
//             while (!dq.empty() && nums[dq.back()] <= nums[i]) {
//                 dq.pop_back();
//             }
//             dq.push_back(i);

//             // Start adding results once first window is completed
//             // The element at the front of deque is the maximum of current
//             // window
//             if (i >= k - 1) {
//                 ans.push_back(nums[dq.front()]);
//             }
//         }

//         return ans;
//     }
// };