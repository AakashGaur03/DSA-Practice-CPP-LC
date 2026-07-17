// // 347. Top K Frequent Elements
// // Medium
// // Topics
// // premium lock icon
// // Companies
// // Given an integer array nums and an integer k, return the k most frequent
// // elements. You may return the answer in any order.

// // Example 1:

// // Input: nums = [1,1,1,2,2,3], k = 2

// // Output: [1,2]

// // Example 2:

// // Input: nums = [1], k = 1

// // Output: [1]

// // Example 3:

// // Input: nums = [1,2,1,2,1,2,3,1,3,2], k = 2

// // Output: [1,2]

// // Constraints:

// // 1 <= nums.length <= 105
// // -104 <= nums[i] <= 104
// // k is in the range [1, the number of unique elements in the array].
// // It is guaranteed that the answer is unique.

// class Solution {
// public:
//     vector<int> topKFrequent(vector<int>& nums, int k) {
//         map<int, int> mpp;
//         for (auto it : nums) {
//             mpp[it]++;
//         }
//         priority_queue<pair<int, int>, vector<pair<int, int>>,
//         greater<pair<int, int>>> minHeap; for (auto it = mpp.begin(); it !=
//         mpp.end(); it++) {
//             minHeap.push({it->second, it->first});
//             if (minHeap.size() > k) {
//                 minHeap.pop();
//             }
//         }
//         vector<int> ans;
//         while (!minHeap.empty()) {
//             auto it = minHeap.top();
//             ans.push_back(it.second);
//             minHeap.pop();
//         }
//         return ans;
//     }
// };