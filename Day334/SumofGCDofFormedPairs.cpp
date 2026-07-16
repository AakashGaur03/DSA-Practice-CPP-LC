// // 3867. Sum of GCD of Formed Pairs
// // Solved
// // Medium
// // Topics
// // premium lock icon
// // Companies
// // Hint
// // You are given an integer array nums of length n.

// // Construct an array prefixGcd where for each index i:

// // Let mxi = max(nums[0], nums[1], ..., nums[i]).
// // prefixGcd[i] = gcd(nums[i], mxi).
// // After constructing prefixGcd:

// // Sort prefixGcd in non-decreasing order.
// // Form pairs by taking the smallest unpaired element and the largest
// unpaired
// // element. Repeat this process until no more pairs can be formed. For each
// // formed pair, compute the gcd of the two elements. If n is odd, the middle
// // element in the prefixGcd array remains unpaired and should be ignored.
// Return
// // an integer denoting the sum of the GCD values of all formed pairs.

// // The term gcd(a, b) denotes the greatest common divisor of a and b.

// // Example 1:

// // Input: nums = [2,6,4]

// // Output: 2

// // Explanation:

// // Construct prefixGcd:

// // i	nums[i]	mxi	prefixGcd[i]
// // 0	2	2	2
// // 1	6	6	6
// // 2	4	6	2
// // prefixGcd = [2, 6, 2]. After sorting, it forms [2, 2, 6].

// // Pair the smallest and largest elements: gcd(2, 6) = 2. The remaining
// middle
// // element 2 is ignored. Thus, the sum is 2.

// class Solution {
// public:
//     int customGcd(int a, int b) {
//         while (a > 0 && b > 0) {
//             if (a > b) {
//                 a = a % b;
//             } else {
//                 b = b % a;
//             }
//         }
//         if (a == 0) {
//             return b;
//         }
//         return a;
//     }

//     long long gcdSum(vector<int>& nums) {
//         int maxi = 0;
//         for (auto& it : nums) {
//             maxi = max(maxi, it);
//             it = customGcd(it, maxi);
//         }
//         // Sort prefixGcd
//         sort(nums.begin(), nums.end());
//         long long res = 0;
//         int i = 0;
//         int j = nums.size() - 1;
//         while (i < j) {
//             res += customGcd(nums[i], nums[j]);
//             i++;
//             j--;
//         }
//         return res;
//     }
// };