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
    bool isValidBST(TreeNode* root) {
        if(root == nullptr) return true;

        vector<int> left = GetTree(root->left);
        vector<int> right = GetTree(root->right);
        sort(left.begin(),left.end());
        sort(right.begin(),right.end());

        if(left.empty() && right.empty()){
            return true;
        }
        
        if(!left.empty()){
            if(left.back() >= root->val) return false;
        }
        if(!right.empty()){
            if(right.front() <= root->val) return false;
        } 
        if(!isValidBST(root->left) || !isValidBST(root->right)) return false;

        return true;
    }

    vector<int> GetTree(TreeNode* root){
        if(root == nullptr) return vector<int>(0);

        vector<int> record = {root->val};
        
        vector<int> left = GetTree(root->left);
        record.insert(record.end(),left.begin(),left.end());

        vector<int> right = GetTree(root->right);
        record.insert(record.end(),right.begin(),right.end());

        return record;
    }
};