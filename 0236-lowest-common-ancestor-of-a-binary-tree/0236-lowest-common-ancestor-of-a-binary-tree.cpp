/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    unordered_set<TreeNode*> record;
    TreeNode* finalAnswer;
    bool haveAnswer = false;
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        bool test = findFirst(root,p);
        bool secondTest = findSecond(root,q);
        return finalAnswer;
    }

    bool findFirst(TreeNode* root,TreeNode* request){
        if(root == nullptr) return false;
        if(root->val == request->val){
            record.insert(root);
            return true;
        }
        
        if(findFirst(root->left,request) || findFirst(root->right,request)){
            record.insert(root);
            return true;
        }

        return false;
    }

    bool findSecond(TreeNode* root,TreeNode* request){
        if(root == nullptr) return false;
        if(root->val == request->val){
            if(!haveAnswer && record.find(root) != record.end()){
                finalAnswer = root;
                haveAnswer = true;
            }
            return true;
        }

        if(findSecond(root->left,request) || findSecond(root->right,request)){
            if(!haveAnswer && record.find(root) != record.end()){
                finalAnswer = root;
                haveAnswer = true;
            }
            return true;
        }

        return false;
    }
};