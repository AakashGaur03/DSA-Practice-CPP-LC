//  Climbing Stairs
// Solved
// Easy
// Topics
// premium lock icon
// Companies
// Hint
// You are climbing a staircase. It takes n steps to reach the top.

// Each time you can either climb 1 or 2 steps. In how many distinct ways can
// you climb to the top?

// Example 1:

// Input: n = 2
// Output: 2
// Explanation: There are two ways to climb to the top.
// 1. 1 step + 1 step
// 2. 2 steps
// Example 2:

// Input: n = 3
// Output: 3
// Explanation: There are three ways to climb to the top.
// 1. 1 step + 1 step + 1 step
// 2. 1 step + 2 steps
// 3. 2 steps + 1 step

class Solution {
public:
  int climbStairs(int n) {
    if (n <= 2)
      return n;

    int prev2 = 1;
    int prev1 = 2;

    for (int i = 3; i <= n; i++) {
      int curr = prev1 + prev2;
      prev2 = prev1;
      prev1 = curr;
    }
    return prev1;
  }
};

// void recursiveCountNumber(int n, int sum, int& res) {
//     if (sum == n) {
//         res++;
//         return;
//     } else if (sum > n) {
//         return;
//     }
//     recursiveCountNumber(n, sum + 1, res);
//     recursiveCountNumber(n, sum + 2, res);
// }
// int climbStairs(int n) {
//     int res = 0;
//     recursiveCountNumber(n, 0, res);
//     return res;
// }
