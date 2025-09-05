// 50. Pow(x, n)
// Solved
// Medium
// Topics
// premium lock icon
// Companies
// Implement pow(x, n), which calculates x raised to the power n (i.e., xn).

// Example 1:

// Input: x = 2.00000, n = 10
// Output: 1024.00000
// Example 2:

// Input: x = 2.10000, n = 3
// Output: 9.26100
// Example 3:

// Input: x = 2.00000, n = -2
// Output: 0.25000
// Explanation: 2-2 = 1/22 = 1/4 = 0.25

// class Solution {
// public:
//     double myPow(double x, int n) {
//         double res = 1;
//         long long m = n;

//         if(m<0) {
//             x = 1/x;
//             m = -m;
//         }

//         while(m>0){
//             if(m%2==1){ // odd
//                 res *= x;
//                 m=m-1;
//             }else{ // even
//                 x *= x;
//                 m = m/2;
//             }
//         }

//     return res;
//     }
// };
//         // if(x == 1) return 1;
//         // double res = 1;
//         // bool isNegative = false;
//         // if(n<0){
//         //     isNegative = true;
//         //     n *= -1; // converts to positive
//         // }
//         // for(int i=0;i<n;i++){
//         //     if(isNegative){
//         //         res/=x;
//         //     }else{
//         //         res*=x;
//         //     }
//         // }
//         // return res;
//         // return pow(x,n);