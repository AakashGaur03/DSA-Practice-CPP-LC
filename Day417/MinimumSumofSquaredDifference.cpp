
// class Solution {
// public:
//     long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int
//     k1,
//                                int k2) {

//         int n = nums1.size();
//         long long k = (long long)k1 + k2;

//         vector<long long> diff(n);
//         long long maxDiff = 0;
//         long long totalDiff = 0;

//         // Step 1: Calculate absolute differences
//         for (int i = 0; i < n; i++) {
//             diff[i] = abs(nums1[i] - nums2[i]);

//             maxDiff = max(maxDiff, diff[i]);
//             totalDiff += diff[i];
//         }

//         // Step 2: If all differences can become zero
//         if (totalDiff <= k) {
//             return 0;
//         }

//         // Step 3: Binary Search for the minimum feasible target
//         long long low = 0;
//         long long high = maxDiff;

//         while (low < high) {
//             long long mid = low + (high - low) / 2;
//             long long operations = 0;

//             for (int i = 0; i < n; i++) {
//                 operations += max(0LL, diff[i] - mid);
//             }

//             if (operations > k) {
//                 low = mid + 1;
//             } else {
//                 high = mid;
//             }
//         }

//         long long target = low;

//         // Step 4: Reduce all differences greater than target
//         for (int i = 0; i < n; i++) {
//             if (diff[i] > target) {
//                 k -= diff[i] - target;
//                 diff[i] = target;
//             }
//         }

//         // Step 5: Use remaining operations
//         for (int i = 0; i < n && k > 0; i++) {
//             if (diff[i] == target) {
//                 diff[i]--;
//                 k--;
//             }
//         }

//         // Step 6: Calculate the sum of squared differences
//         long long sum = 0;

//         for (int i = 0; i < n; i++) {
//             sum += diff[i] * diff[i];
//         }

//         return sum;
//     }
// };

// //  long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int
// k1,
// //                                int k2) {
// //         // TC : (O(n log n+k log n)
// //         // TLE
// //         int n = nums1.size();
// //         long long sum = 0;
// //         int k = k1 + k2;
// //         priority_queue<long long> absDiff;

// //         for (int i = 0; i < n; i++) {
// //             long long val = abs(nums1[i] - nums2[i]);
// //             absDiff.push(val);
// //         }
// //         while (k > 0 && absDiff.top() > 0) {
// //             long long topVal = absDiff.top();
// //             absDiff.pop();
// //             absDiff.push(topVal - 1);
// //             k--;
// //         }

// //         while (!absDiff.empty()) {
// //             long long topVal = absDiff.top();
// //             absDiff.pop();

// //             sum += topVal * topVal;
// //         }
// //         return sum;
// //     }