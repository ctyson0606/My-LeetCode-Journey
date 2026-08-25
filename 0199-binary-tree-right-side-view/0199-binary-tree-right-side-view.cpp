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
    vector<int> finalAnswer;
    unordered_set<int> record;
public:
    vector<int> rightSideView(TreeNode* root) {
        findRight(root,0);

        return finalAnswer;
    }

    void findRight(TreeNode* root, int depth){
        if(root != nullptr){
            if(record.find(depth) == record.end()){
                record.insert(depth);
                finalAnswer.push_back(root->val);
            }

            findRight(root->right,depth+1);
            findRight(root->left,depth+1);
        }
    }


};