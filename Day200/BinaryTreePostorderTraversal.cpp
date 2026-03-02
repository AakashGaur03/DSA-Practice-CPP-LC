// // Binary Tree Postorder Traversal
// // Solved
// // Easy
// // Topics
// // premium lock icon
// // Companies
// // Given the root of a binary tree, return the postorder traversal of its
// nodes'
// // values.

// // Example 1:

// // Input: root = [1,null,2,3]

// // Output: [3,2,1]

// // Explanation:

// // Example 2:

// // Input: root = [1,2,3,4,5,null,8,null,null,6,7,9]

// // Output: [4,6,7,5,2,9,8,3,1]

// // Explanation:

// // Example 3:

// // Input: root = []

// // Output: []

// // Example 4:

// // Input: root = [1]

// // Output: [1]

// // Constraints:

// // The number of the nodes in the tree is in the range [0, 100].
// // -100 <= Node.val <= 100

// // Follow up: Recursive solution is trivial, could you do it iteratively?

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
//     // void postorderTraversalFunc(TreeNode* root,vector<int> &arr){
//     //         if (root == nullptr)
//     //             return;

//     //         postorderTraversalFunc(root->left, arr);
//     //         postorderTraversalFunc(root->right, arr);
//     //         arr.push_back(root->val);
//     // }
//     vector<int>  postorderTraversalIterative2Stack(TreeNode* root) {
//         vector<int> postOrder;
//         if (root == nullptr)
//             return postOrder;

//         stack<TreeNode*> st1, st2;
//         st1.push(root);

//         while (!st1.empty()) {
//             root = st1.top();
//             st1.pop();
//             st2.push(root);

//             if (root->left) {
//                 st1.push(root->left);
//             }
//             if (root->right) {
//                 st1.push(root->right);
//             }
//         }

//         while (!st2.empty()) {
//             postOrder.push_back(st2.top()->val);
//             st2.pop();
//         }
//         return postOrder;
//     }

//     vector<int> postorderTraversal(TreeNode* root) {
//         vector<int> arr = postorderTraversalIterative2Stack(root);

//         return arr;
//     }
// };