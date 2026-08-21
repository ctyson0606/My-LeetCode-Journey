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
    unordered_map<int,int> indexRecord;
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        TreeNode* root = new TreeNode(postorder[postorder.size()-1]);
        int i = 0;
        int index;
        while(i < inorder.size()){
            indexRecord[postorder[i]] = i;
            if(inorder[i] == root->val) index = i;
            i++;
        }
        root->left = buildingTree(postorder,inorder,0,index-1);
        root->right = buildingTree(postorder,inorder,index+1,inorder.size()-1);
        return root;
    }

    TreeNode* buildingTree(vector<int>& postorder, vector<int> inorder, int startIdx, int endIdx){
        if(startIdx > endIdx) return nullptr;
        
        if(startIdx == endIdx){
            TreeNode* root = new TreeNode(inorder[startIdx]);
            return root;
        }

        int i = startIdx;
        int maxIdx = -1;
        while(i < endIdx+1){
            if(maxIdx == -1 || indexRecord[inorder[i]] > indexRecord[inorder[maxIdx]]) maxIdx = i;
            i++;
        }
        TreeNode* root = new TreeNode(inorder[maxIdx]);
        root->right = buildingTree(postorder,inorder,maxIdx+1,endIdx);
        root->left = buildingTree(postorder,inorder,startIdx,maxIdx-1);
        return root;
    }
};