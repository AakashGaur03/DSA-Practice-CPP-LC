// // Construct Binary Tree from Inorder and Postorder Traversal
// // Solved
// // Medium
// // Topics
// // premium lock icon
// // Companies
// // Given two integer arrays inorder and postorder where inorder is the
// inorder
// // traversal of a binary tree and postorder is the postorder traversal of the
// // same tree, construct and return the binary tree.

// // Example 1:

// // Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
// // Output: [3,9,20,null,null,15,7]
// // Example 2:

// // Input: inorder = [-1], postorder = [-1]
// // Output: [-1]

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
//     TreeNode* buildBinaryTree(vector<int>& postorder, int postStart,
//                               int postEnd, vector<int>& inorder, int inStart,
//                               int inEnd, map<int, int>& inMap) {

//         if (postStart > postEnd || inStart > inEnd) {
//             return nullptr;
//         }
//         TreeNode* node = new TreeNode(postorder[postEnd]);
//         int inRoot = inMap[node->val];
//         int numsLeft = inRoot - inStart;

//         node->left =
//             buildBinaryTree(postorder, postStart, postStart + numsLeft - 1,
//                             inorder, inStart, inRoot - 1, inMap);

//         node->right =
//             buildBinaryTree(postorder, postStart + numsLeft, postEnd - 1,
//                             inorder, inRoot + 1, inEnd, inMap);

//         return node;

//         return node;
//     }
//     TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
//         map<int, int> inMap;

//         for (int i = 0; i < inorder.size(); i++) {
//             inMap[inorder[i]] = i;
//         }

//         TreeNode* root = buildBinaryTree(postorder, 0, postorder.size() - 1,
//                                          inorder, 0, inorder.size() - 1,
//                                          inMap);

//         return root;
//     }
// };