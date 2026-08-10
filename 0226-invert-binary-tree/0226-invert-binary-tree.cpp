/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        invertTreeF(root);
        return root;
    }

    void invertTreeF(TreeNode* root){
        if(root != nullptr){
            TreeNode* test = root->left;
            root->left = root->right;
            root->right = test;
            invertTreeF(root->left);
            invertTreeF(root->right);
        }
    }
};