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
    int kthSmallest(TreeNode* root, int k) {
        GetTre(root);
        sort(record.begin(),record.end());

        return record[k-1];
    }

    void GetTre(TreeNode* root){
        if(root != nullptr){
            record.push_back(root->val);

            GetTre(root->left);
            GetTre(root->right);
        }
    }
};