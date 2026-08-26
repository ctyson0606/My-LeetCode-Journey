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
private:
    vector<int> record;
public:
    int getMinimumDifference(TreeNode* root) {
        GetTree(root);
        
        sort(record.begin(),record.end());
        int minNum = record[1] - record[0];
        for(int i = 1; i < record.size()-1; i++){
            int min = record[i+1] - record[i];
            if(min < minNum) minNum = min;
        }
        return minNum;
    }

    void GetTree(TreeNode* root){
        if(root != nullptr){
            record.push_back(root->val);

            GetTree(root->left);
            GetTree(root->right);
        }
    }
};