// // Binary Tree Preorder Traversal
// // Solved
// // Easy
// // Topics
// // premium lock icon
// // Companies
// // Given the root of a binary tree, return the preorder traversal of its
// nodes' values.

// // Example 1:

// // Input: root = [1,null,2,3]

// // Output: [1,2,3]

// // Explanation:

// // Example 2:

// // Input: root = [1,2,3,4,5,null,8,null,null,6,7,9]

// // Output: [1,2,4,5,6,7,3,8,9]

// // Explanation:

// // Example 3:

// // Input: root = []

// // Output: []

// // Example 4:

// // Input: root = [1]

// // Output: [1]

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
//     void preorderTraversalFunc(TreeNode* root, vector<int>& arr) {
//         if (root == nullptr)
//             return;

//         arr.push_back(root->val);
//         preorderTraversalFunc(root->left, arr);
//         preorderTraversalFunc(root->right, arr);
//     }
//     vector<int> preorderTraversal(TreeNode* root) {
//         vector<int> arr;
//         preorderTraversalFunc(root, arr);

//         return arr;
//     }
// };