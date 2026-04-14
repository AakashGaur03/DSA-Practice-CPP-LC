// // Maximum Sum BST in Binary Tree
// // Solved
// // Hard
// // Topics
// // premium lock icon
// // Companies
// // Hint
// // Given a binary tree root, return the maximum sum of all keys of any
// sub-tree
// // which is also a Binary Search Tree (BST).

// // Assume a BST is defined as follows:

// // The left subtree of a node contains only nodes with keys less than the
// node's
// // key. The right subtree of a node contains only nodes with keys greater
// than
// // the node's key. Both the left and right subtrees must also be binary
// search
// // trees.

// // Example 1:

// // Input: root = [1,4,3,2,4,2,5,null,null,null,null,null,null,4,6]
// // Output: 20
// // Explanation: Maximum sum in a valid Binary search tree is obtained in root
// // node with key equal to 3. Example 2:

// // Input: root = [4,3,null,1,2]
// // Output: 2
// // Explanation: Maximum sum in a valid Binary search tree is obtained in a
// // single root node with key equal to 2. Example 3:

// // Input: root = [-4,-2,-5]
// // Output: 0
// // Explanation: All values are negatives. Return an empty BST.

// // Constraints:

// // The number of nodes in the tree is in the range [1, 4 * 104].
// // -4 * 104 <= Node.val <= 4 * 104

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

// class NodeValue {
// public:
//     int minNode, maxNode, sum;

//     NodeValue(int minNode, int maxNode, int sum) {
//         this->maxNode = maxNode;
//         this->minNode = minNode;
//         this->sum = sum;
//     }
// };

// class Solution {
// public:

//     NodeValue largestBSTinBinaryTree(TreeNode* root,int &maxSum) {
//         if (!root) {
//             // Send so that it can be compared Easily
//             return NodeValue(INT_MAX, INT_MIN, 0);
//         }

//         auto left = largestBSTinBinaryTree(root->left,maxSum);
//         auto right = largestBSTinBinaryTree(root->right,maxSum);

//         if (left.maxNode < root->val && root->val < right.minNode) {
//             // It is a BST

//             int currSum = left.sum + right.sum + root->val;

//             maxSum = max(maxSum, currSum);

//             return NodeValue(min(root->val, left.minNode),
//                              max(root->val, right.maxNode),
//                              left.sum + right.sum + root->val);
//         }
//         return NodeValue(INT_MIN, INT_MAX, max(left.sum, 0));
//     }

//     int maxSumBST(TreeNode* root) {
//         int sum = 0;
//         NodeValue result = largestBSTinBinaryTree(root,sum);
//         return sum;
//     }
// };