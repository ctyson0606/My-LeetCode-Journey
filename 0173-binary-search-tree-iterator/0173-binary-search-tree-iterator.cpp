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
class BSTIterator {
private:
    vector<TreeNode*> record;
    int index = -1;
public:
    BSTIterator(TreeNode* root) {
        record = BuildOneD(root);
    }

    vector<TreeNode*> BuildOneD(TreeNode* root){
        if(root == nullptr) return vector<TreeNode*>(0);

        vector<TreeNode*> mix;

        vector<TreeNode*> left = BuildOneD(root->left);
        mix.insert(mix.end(),left.begin(),left.end());

        mix.push_back(root);

        vector<TreeNode*> right = BuildOneD(root->right);
        mix.insert(mix.end(),right.begin(),right.end());

        return mix;
    }
    
    int next() {
        index++;
        return record[index]->val;
    }
    
    bool hasNext() {
        if(index+1 < record.size()) return true;

        return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */