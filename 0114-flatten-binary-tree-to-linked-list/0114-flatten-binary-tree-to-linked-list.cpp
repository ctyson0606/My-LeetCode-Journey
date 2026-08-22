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
    void flatten(TreeNode* root) {
        vector<TreeNode*> temp = GetList(root);
        if(temp.size() >= 2){
            for(int i = 0;i < temp.size()-1;i++){
                temp[i]->right = temp[i+1];
                temp[i]->left = nullptr;
            } 
        }
    }

    vector<TreeNode*> GetList(TreeNode* root){
        if(root == nullptr) return vector<TreeNode*>(0);

        vector<TreeNode*> mix = {root};

        vector<TreeNode*> left = GetList(root->left);
        mix.insert(mix.end(),left.begin(),left.end());

        vector<TreeNode*> right = GetList(root->right);
        mix.insert(mix.end(),right.begin(),right.end());

        return mix;
    }
};