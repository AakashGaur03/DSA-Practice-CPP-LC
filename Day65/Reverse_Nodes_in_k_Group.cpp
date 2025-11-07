// // Reverse Nodes in k-Group
// // Solved
// // Hard
// // Topics
// // premium lock icon
// // Companies
// // Given the head of a linked list, reverse the nodes of the list k at a
// time,
// // and return the modified list.

// // k is a positive integer and is less than or equal to the length of the
// linked
// // list. If the number of nodes is not a multiple of k then left-out nodes,
// in
// // the end, should remain as it is.

// // You may not alter the values in the list's nodes, only nodes themselves
// may
// // be changed.

// // Example 1:

// // Input: head = [1,2,3,4,5], k = 2
// // Output: [2,1,4,3,5]
// // Example 2:

// // Input: head = [1,2,3,4,5], k = 3
// // Output: [3,2,1,4,5]

// // Constraints:

// // The number of nodes in the list is n.
// // 1 <= k <= n <= 5000
// // 0 <= Node.val <= 1000

// // Follow-up: Can you solve the problem in O(1) extra memory space?

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
//     ListNode* findKthNode(ListNode* temp, int k) {
//         k -= 1;
//         while (temp != NULL && k > 0) {
//             k--;
//             temp = temp->next;
//         }
//         return temp;
//     }
//     ListNode* reverse(ListNode* head) {
//         if (head == NULL || head->next == NULL) {
//             return head;
//         }
//         ListNode* newHead = reverse(head->next);
//         ListNode* front = head->next;
//         front->next = head;
//         head->next = NULL;

//         return newHead;
//     }

//     ListNode* reverseKGroup(ListNode* head, int k) {
//         ListNode* temp = head;
//         ListNode* prevLast = NULL;
//         while (temp != NULL) {
//             // Find Kth Node
//             ListNode* KthNode = findKthNode(temp, k);

//             if(KthNode == NULL){
//                 // NEED TO HANDLE LAST CASE

//                 if(prevLast){
//                     prevLast->next = temp;
//                 }
//                 break;
//             }

//             // Disconnect Kth group and reverse
//             ListNode * nextNode = KthNode->next;
//             KthNode->next = NULL;
//             reverse(temp);

//             // Do we need to update head
//             if(temp == head){
//                 head = KthNode;
//             }else{
//                 prevLast->next = KthNode;
//             }
//             prevLast = temp;

//             temp = nextNode;

//         }
//         return head;
//     }
// };

// // // First loop Break LL into K groups
// // // means point last of K to next
// // 1->2->NULL 3->4
// //     ->NULL 5
// //     // Reverse
// //     NULL->2->1. 4->3. 5

// //     // Note to remember Head of start one and last of second one
