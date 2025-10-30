// // Sort List
// // Solved
// // Medium
// // Topics
// // premium lock icon
// // Companies
// // Given the head of a linked list, return the list after sorting it in
// ascending order.

// // Example 1:

// // Input: head = [4,2,1,3]
// // Output: [1,2,3,4]
// // Example 2:

// // Input: head = [-1,5,3,4,0]
// // Output: [-1,0,3,4,5]
// // Example 3:

// // Input: head = []
// // Output: []

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
//     ListNode* findMiddle(ListNode* head) {
//         ListNode* slow = head;
//         ListNode* fast = head->next; // need first middle in even cases
//         while (fast != NULL && fast->next != NULL) {
//             fast = fast->next->next;
//             slow = slow->next;
//         }
//         return slow;
//     }
//     ListNode* mergeTwoLinkedList(ListNode* temp1, ListNode* temp2) {
//         ListNode* dummyNode = new ListNode(-1);
//         ListNode* temp = dummyNode;

//         while (temp1 != NULL && temp2 != NULL) {
//             if (temp1->val < temp2->val) {
//                 temp->next = temp1;
//                 temp1 = temp1->next;
//             } else {
//                 temp->next = temp2;
//                 temp2 = temp2->next;
//             }
//                 temp = temp->next;
//         }
//         if (temp1) {
//             temp->next = temp1;
//             temp1 = temp1->next;
//         } else {
//             temp->next = temp2;
//             temp2 = temp2->next;
//         }
//         return dummyNode->next;
//     }
//     ListNode* sortList(ListNode* head) {
//         // using concept of merge Sort
//         // find middle using tortoise and hare
//         // then divide them till single element
//         // merge using sorting two LL concept

//         if (head == NULL || head->next == NULL) {
//             return head;
//         }
//         ListNode* middleNode = findMiddle(head);
//         ListNode* leftHead = head;
//         ListNode* rightHead = middleNode->next;
//         middleNode->next = NULL;

//         leftHead = sortList(leftHead);
//         rightHead = sortList(rightHead);

//         return mergeTwoLinkedList(leftHead, rightHead);
//     }
// };