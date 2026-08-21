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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* root = new TreeNode(preorder[0]);
        int i = 0;
        int index;
        while(i < inorder.size()){
            indexRecord[preorder[i]] = i;
            if(inorder[i] == root->val) index = i;
            i++;
        }
        root->left = buildingTree(preorder,inorder,0,index-1);
        root->right = buildingTree(preorder,inorder,index+1,inorder.size()-1);
        return root;
    }

    TreeNode* buildingTree(vector<int>& preorder, vector<int> inorder, int startIdx, int endIdx){
        if(startIdx > endIdx) return nullptr;
        
        if(startIdx == endIdx){
            TreeNode* root = new TreeNode(inorder[startIdx]);
            return root;
        }

        int i = startIdx;
        int minIdx = -1;
        while(i < endIdx+1){
            if(minIdx == -1 || indexRecord[inorder[i]] < indexRecord[inorder[minIdx]]) minIdx = i;
            i++;
        }
        TreeNode* root = new TreeNode(inorder[minIdx]);
        root->right = buildingTree(preorder,inorder,minIdx+1,endIdx);
        root->left = buildingTree(preorder,inorder,startIdx,minIdx-1);
        return root;
    }

};