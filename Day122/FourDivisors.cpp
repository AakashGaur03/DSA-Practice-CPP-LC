// // Four Divisors
// // Solved
// // Medium
// // Topics
// // premium lock icon
// // Companies
// // Hint
// // Given an integer array nums, return the sum of divisors of the integers in
// // that array that have exactly four divisors. If there is no such integer in
// // the array, return 0.

// // Example 1:

// // Input: nums = [21,4,7]
// // Output: 32
// // Explanation:
// // 21 has 4 divisors: 1, 3, 7, 21
// // 4 has 3 divisors: 1, 2, 4
// // 7 has 2 divisors: 1, 7
// // The answer is the sum of divisors of 21 only.
// // Example 2:

// // Input: nums = [21,21]
// // Output: 64
// // Example 3:

// // Input: nums = [1,2,3,4,5]
// // Output: 0

// class Solution {
// public:
//     vector<int> findDivisors(int number) {
//         vector<int> divisors;
//         int sqrRoot = sqrt(number);
//         for (int i = 1; i <= sqrRoot; i++) {
//             if (number % i == 0) {
//                 divisors.push_back(i);
//                 if (i != number / i) {
//                     divisors.push_back(number / i);
//                 }
//             }
//             if (divisors.size() > 4)
//                 return {};
//         }
//         if (divisors.size() < 4)
//             return {};
//         return divisors;
//     }
//     int sumFourDivisors(vector<int>& nums) {
//         int n = nums.size();
//         int sum = 0;
//         for (int i = 0; i < n; i++) {
//             vector<int> divisorsOfNum = findDivisors(nums[i]);
//             for (int j = 0; j < divisorsOfNum.size(); j++) {
//                 sum += divisorsOfNum[j];
//             }
//         }
//         return sum;
//     }
// };