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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> finalAnswer;
        
        GetOrder(root,0);
        for(int i = 0;i < maxDepth+1;i++){
            double sum = 0;
            for(int j = 0; j < record[i].size() ; j++){
                sum += double(record[i][j]);
            }
            double average = sum / record[i].size();
            finalAnswer.push_back(average);
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