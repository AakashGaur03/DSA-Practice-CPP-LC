// // Convert Binary Number in a Linked List to Integer
// // Solved
// // Easy
// // Topics
// // premium lock icon
// // Companies
// // Hint
// // Given head which is a reference node to a singly-linked list. The value of
// // each node in the linked list is either 0 or 1. The linked list holds the
// // binary representation of a number.

// // Return the decimal value of the number in the linked list.

// // The most significant bit is at the head of the linked list.

// // Example 1:

// // Input: head = [1,0,1]
// // Output: 5
// // Explanation: (101) in base 2 = (5) in base 10
// // Example 2:

// // Input: head = [0]
// // Output: 0

// // Constraints:

// // The Linked List is not empty.
// // Number of nodes will not exceed 30.
// // Each node's value is either 0 or 1.

// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */
// class Solution {
// public:
//     int getDecimalValue(ListNode* head) {
//         int res = 0;
//         while (head != NULL) {
//             // value = value * 2 + bit
//             // Left shift (<< 1) means:
//             // Multiply the number by 2
//             res = (res << 1) | head->val;
//             head = head->next;
//         }
//         return res;
//     }
// };

// // int convertToDecimal(string x) {
// //     int len = x.size();
// //     int num = 0;
// //     int powerOfTwo = 1;
// //     for (int i = len - 1; i >= 0; i--) {
// //         if (x[i] == '1') {
// //             num += powerOfTwo;
// //         }
// //         powerOfTwo *= 2;
// //     }
// //     return num;
// // }
// // int getDecimalValue(ListNode* head) {
// //     string binaryDigits = "";
// //     while (head != NULL) {
// //         binaryDigits = binaryDigits + char('0' + head->val);
// //         head = head->next;
// //     }
// //     return convertToDecimal(binaryDigits);
// // }
