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
    bool hasPathSum(TreeNode* root, int targetSum) {
        return PathSum(root,targetSum,0);
    }

    bool PathSum(TreeNode* root, int targetSum, int Sum){
        if(root == nullptr) return false;

        Sum += root->val;
        if(root->left == nullptr && root->right == nullptr){
            if(Sum > targetSum) return false;
            if(Sum == targetSum) return true;
        }

        bool left = PathSum(root->left,targetSum, Sum);
        if(left) return true;

        bool right = PathSum(root->right,targetSum,Sum);
        if(right) return true;

        return false;
    }

};