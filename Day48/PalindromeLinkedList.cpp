// // 234. Palindrome Linked List
// // Solved
// // Easy
// // Topics
// // premium lock icon
// // Companies
// // Given the head of a singly linked list, return true if it is a palindrome
// or false otherwise.

// // Example 1:

// // Input: head = [1,2,2,1]
// // Output: true
// // Example 2:

// // Input: head = [1,2]
// // Output: false

// // Constraints:

// // The number of nodes in the list is in the range [1, 105].
// // 0 <= Node.val <= 9

// // Follow up: Could you do it in O(n) time and O(1) space?

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
//     ListNode* reverseLL(ListNode* head) {
//         if (head == NULL || head->next == NULL)
//             return head;

//         ListNode* newHead = reverseLL(head->next);
//         ListNode* front = head->next;
//         front->next = head;
//         head->next = NULL;

//         return newHead;
//     }
//     bool isPalindrome(ListNode* head) {
//         // TC O(2N)
//         // SC O(1)
//         ListNode* slow = head;
//         ListNode* fast = head;

//         while (fast->next != NULL && fast->next->next != NULL) {
//             slow = slow->next;
//             fast = fast->next->next;
//         }

//         // We reverse the second Half
//         ListNode* newHead = reverseLL(slow->next);
//         ListNode* first = head;
//         ListNode* second = newHead;
//         while (second != NULL) {
//             if (first->val != second->val) {
//                 reverseLL(newHead); // Back to original
//                 return false;
//             }
//             first = first->next;
//             second = second->next;
//         }
//         reverseLL(newHead); // Back to original
//         return true;
//     }
// };

// // bool isPalindrome(ListNode* head) {
// //     // TC O(2n)
// //     // SC O(n)
// //     if (head == NULL || head->next == NULL) {
// //         return true;
// //     }
// //     ListNode* temp = head;
// //     stack<int> st;
// //     while(temp!=NULL){
// //         st.push(temp->val);
// //         temp = temp->next;
// //     }
// //     temp = head;
// //     while(temp!=NULL){
// //         if(temp->val != st.top()){
// //             return false;
// //         }
// //         st.pop();
// //         temp = temp->next;
// //     }
// //     return true;
// // }