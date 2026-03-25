// // Binary Tree Inorder Traversal
// // Solved
// // Easy
// // Topics
// // premium lock icon
// // Companies
// // Given the root of a binary tree, return the inorder traversal of its
// nodes'
// // values.

// // Example 1:

// // Input: root = [1,null,2,3]

// // Output: [1,3,2]

// // Explanation:

// // Example 2:

// // Input: root = [1,2,3,4,5,null,8,null,null,6,7,9]

// // Output: [4,2,6,5,7,1,3,9,8]

// // Explanation:

// // Example 3:

// // Input: root = []

// // Output: []

// // Example 4:

// // Input: root = [1]

// // Output: [1]

// // Constraints:

// // The number of nodes in the tree is in the range [0, 100].
// // -100 <= Node.val <= 100

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
//     // void inorderTraversalFunc(TreeNode* root, vector<int>& arr) {
//     //     if (root == nullptr)
//     //         return;

//     //     inorderTraversalFunc(root->left, arr);
//     //     arr.push_back(root->val);
//     //     inorderTraversalFunc(root->right, arr);
//     // }
//     // Morris Traversal
//     vector<int> getInorder(TreeNode* root) {
//         // TC O(N)
//         // SC O(1)
//         vector<int> inorder;
//         TreeNode* curr = root;
//         while (curr != nullptr) {
//             // If no left child visit Node and go left
//             if (curr->left == nullptr) {
//                 inorder.push_back(curr->val);
//                 curr = curr->right;
//             } else {
//                 // Left Child exists
//                 TreeNode* prev = curr->left;
//                 // Find rightmost node in left subtree
//                 while (prev->right && prev->right != curr) {
//                     prev = prev->right;
//                 }

//                 // First time visiting this node create thread
//                 if (prev->right == nullptr) {
//                     prev->right = curr;
//                     curr = curr->left;
//                 } else {
//                     prev->right = nullptr;
//                     inorder.push_back(curr->val);
//                     curr = curr->right;
//                 }
//             }
//         }
//         return inorder;
//     }

//     vector<int> inorderTraversal(TreeNode* root) {
//         // vector<int> arr;
//         // inorderTraversalFunc(root, arr);
//         vector<int> arr = getInorder(root);

//         return arr;
//     }
// };