// // Balanced Binary Tree
// // Solved
// // Easy
// // Topics
// // premium lock icon
// // Companies
// // Given a binary tree, determine if it is height-balanced.

// // Example 1:

// // Input: root = [3,9,20,null,null,15,7]
// // Output: true
// // Example 2:

// // Input: root = [1,2,2,3,3,null,null,4,4]
// // Output: false
// // Example 3:

// // Input: root = []
// // Output: true

// // Constraints:

// // The number of nodes in the tree is in the range [0, 5000].
// // -104 <= Node.val <= 104

// // Seen this question in a real interview before?
// // 1/5
// // Yes
// // No
// // Accepted
// // 2,399,888/4.1M
// // Acceptance Rate
// // 57.9%

// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
//  * right(right) {}
//  * };
//  */
// class Solution {
// public:
//     int checkMaxDepth(TreeNode* root) {
//         if (root == nullptr) {
//             return 0;
//         }
//         int lh = checkMaxDepth(root->left);
//         if (lh == -1) {
//             return -1;
//         }
//         int rh = checkMaxDepth(root->right);
//         if (rh == -1) {
//             return -1;
//         }

//         if (abs(lh - rh) > 1)
//             return -1;

//         return 1 + max(lh, rh);
//     }
//     bool isBalanced(TreeNode* root) { return checkMaxDepth(root) != -1; }
// };