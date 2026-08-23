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
    vector<int> sumMix;
public:
    int sumNumbers(TreeNode* root) {
        sumNumber(root,0);
        int sum = 0;
        for(int i = 0; i < sumMix.size() ; i++){
            sum += sumMix[i];
        }
        return sum;
    }

    void sumNumber(TreeNode* root, int sum){
        sum *= 10;
        sum += root->val;
        if(root->left == nullptr && root->right == nullptr){
            sumMix.push_back(sum);
        }
        else{
            if(root->left != nullptr){
                sumNumber(root->left,sum);
            }
            if(root->right != nullptr){
                sumNumber(root->right,sum);
            }
        }
    }
};