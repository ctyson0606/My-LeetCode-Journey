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
    unordered_map<int,vector<int>> record;
    int maxDepth = 0;
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> finalAnswer;

        if(root == nullptr) return finalAnswer;
        
        GetOrder(root,0);
        for(int i = 0;i < maxDepth+1;i++){
            finalAnswer.push_back(record[i]);
        }

        return finalAnswer;
    }

    void GetOrder(TreeNode* root, int depth){
        if(root != nullptr){
            if(record.find(depth) == record.end()){
                record[depth] = {root->val};
            }
            else{
                record[depth].push_back(root->val);
            }

            if(depth > maxDepth) maxDepth = depth;

            GetOrder(root->left,depth+1);
            GetOrder(root->right,depth+1);
        }
    }

    
};