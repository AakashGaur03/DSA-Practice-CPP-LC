
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
//     // vector<int>  postorderTraversalIterative2Stack(TreeNode* root) {
//     //     vector<int> postOrder;
//     //     if (root == nullptr)
//     //         return postOrder;

//     //     stack<TreeNode*> st1, st2;
//     //     st1.push(root);

//     //     while (!st1.empty()) {
//     //         root = st1.top();
//     //         st1.pop();
//     //         st2.push(root);

//     //         if (root->left) {
//     //             st1.push(root->left);
//     //         }
//     //         if (root->right) {
//     //             st1.push(root->right);
//     //         }
//     //     }

//     //     while (!st2.empty()) {
//     //         postOrder.push_back(st2.top()->val);
//     //         st2.pop();
//     //     }
//     //     return postOrder;
//     // }
//     vector<int> postorderTraversalIterative1Stack(TreeNode* root) {
//         vector<int> postOrder;
//         if (root == nullptr)
//             return postOrder;

//         stack<TreeNode*> st;
//         TreeNode* curr = root;
//         TreeNode* lastVisited = nullptr;
//         while (curr != nullptr || !st.empty()) {
//             if (curr != nullptr) {
//                 st.push(curr);
//                 curr = curr->left;
//             } else {
//                 TreeNode* peekNode = st.top();
//                 if (peekNode->right != nullptr &&
//                     lastVisited != peekNode->right) {
//                     curr = peekNode->right;
//                 } else {
//                     postOrder.push_back(peekNode->val);
//                     lastVisited = peekNode;
//                     st.pop();
//                 }
//             }
//         }
//         return postOrder;
//     }

//     vector<int> postorderTraversal(TreeNode* root) {
//         vector<int> arr = postorderTraversalIterative1Stack(root);

//         return arr;
//     }
// };