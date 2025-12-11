// // Pow(x, n)
// // Solved
// // Medium
// // Topics
// // premium lock icon
// // Companies
// // Implement pow(x, n), which calculates x raised to the power n (i.e., xn).

// // Example 1:

// // Input: x = 2.00000, n = 10
// // Output: 1024.00000
// // Example 2:

// // Input: x = 2.10000, n = 3
// // Output: 9.26100
// // Example 3:

// // Input: x = 2.00000, n = -2
// // Output: 0.25000
// // Explanation: 2-2 = 1/22 = 1/4 = 0.25

// // Constraints:

// // -100.0 < x < 100.0
// // -231 <= n <= 231-1
// // n is an integer.
// // Either x is not zero or n > 0.
// // -104 <= xn <= 104

// class Solution {
// public:
//     double recursivePow(double x, long n, double ans) {
//         if (n == 0)
//             return ans;

//         if (n % 2 != 0) {
//             ans = ans * x;
//             n--;
//             return recursivePow(x, n, ans);
//         } else {
//             return recursivePow(x * x, n / 2, ans);
//         }
//     }
//     double myPow(double x, int n) {
//         long m = n;
//         if(m<0){
//             x=1/x;
//             m=-m;
//         }
//         // we used m cause of overflow scenario
//         return recursivePow(x, m, 1);
//         }
// };
