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
    bool isSymmetric(TreeNode* root) {
        invertTreeF(root->right);
        return isSameTree(root->left,root->right);
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

    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == nullptr && q == nullptr) return true;
        else if(p ==  nullptr || q == nullptr) return false;

        if(p->val != q->val) return false;

        bool left = isSameTree(p->left,q->left);
        bool right = isSameTree(p->right,q->right);

        if(!left || !right) return false;

        return true;
    }

};