// // Binary Tree Right Side View
// // Solved
// // Medium
// // Topics
// // premium lock icon
// // Companies
// // Given the root of a binary tree, imagine yourself standing on the right
// side
// // of it, return the values of the nodes you can see ordered from top to
// bottom.

// // Example 1:

// // Input: root = [1,2,3,null,5,null,4]

// // Output: [1,3,4]

// // Explanation:

// // Example 2:

// // Input: root = [1,2,3,4,null,null,null,5]

// // Output: [1,3,4,5]

// // Explanation:

// // Example 3:

// // Input: root = [1,null,3]

// // Output: [1,3]

// // Example 4:

// // Input: root = []

// // Output: []

// // Constraints:

// // The number of nodes in the tree is in the range [0, 100].

// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
//  right(right) {}
//  * };
//  */
// class Solution {
// public:
//     void rightSideViewHelper(TreeNode* root,int level,vector<int> &res){
//         if(root == nullptr){
//             return;
//         }
//         if(res.size() == level){
//             res.push_back(root->val);
//         }
//         rightSideViewHelper(root->right,level+1,res);
//         rightSideViewHelper(root->left,level+1,res);
//     }
//     vector<int> rightSideView(TreeNode* root) {
//         vector<int>res;
//         rightSideViewHelper(root,0,res);
//         return res;

//     }
// };