// // Multiply Strings
// // Solved
// // Medium
// // Topics
// // premium lock icon
// // Companies
// // Given two non-negative integers num1 and num2 represented as strings,
// return
// // the product of num1 and num2, also represented as a string.

// // Note: You must not use any built-in BigInteger library or convert the
// inputs
// // to integer directly.

// // Example 1:

// // Input: num1 = "2", num2 = "3"
// // Output: "6"
// // Example 2:

// // Input: num1 = "123", num2 = "456"
// // Output: "56088"

// // Constraints:

// // 1 <= num1.length, num2.length <= 200
// // num1 and num2 consist of digits only.
// // Both num1 and num2 do not contain any leading zero, except the number 0
// // itself.

// class Solution {
// public:
//     // long long getNumberFromString(string num) {
//     //     long long number = 0;
//     //     for (int i = 0; i < num.size(); i++) {
//     //         number = number * 10 + (num[i] - '0');
//     //     }
//     //     return number;
//     // }
//     // string stringFromNumber(long long number) {
//     //     if (number == 0)
//     //         return "0";
//     //     string ans = "";
//     //     while (number > 0) {
//     //         ans += (number % 10) + '0';
//     //         number = number / 10;
//     //     }
//     //     reverse(ans.begin(), ans.end());
//     //     return ans;
//     // }
//     // string multiply(string num1, string num2) {
//     //     long long n1 = getNumberFromString(num1);
//     //     long long n2 = getNumberFromString(num2);
//     //     long long n3 = n1 * n2;
//     //     return stringFromNumber(n3);
//     // }
//     string multiply(string num1, string num2) {
//         if (num1 == "0" || num2 == "0")
//             return "0";

//         int n = num1.size();
//         int m = num2.size();
//         vector<int> result(n + m, 0);
//         for (int i = n - 1; i >= 0; i--) {
//             for (int j = m - 1; j >= 0; j--) {
//                 int mul = (num1[i] - '0') * (num2[j] - '0');
//                 int sum = mul + result[i + j + 1];
//                 result[i + j + 1] = sum % 10; // Current Digit
//                 result[i + j] += sum / 10; // Carry
//             }
//         }
//         string ans = "";
//         for (int num : result) {
//             if (!(ans.empty() && num == 0)) {
//                 ans += (num + '0');
//             }
//         }
//         return ans.empty() ? "0" : ans;
//     }
// };