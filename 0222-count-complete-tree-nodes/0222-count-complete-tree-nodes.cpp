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
public:
    int countNodes(TreeNode* root) {
        int left = depthCountLeft(root,0);
        int right = depthCountRight(root,0);

        if(root == nullptr) return 0;
        int temp = 0;
        int finalAnswer = 0;
        while(temp < right){
            finalAnswer += pow(2,temp);
            temp++;
        }

        if(left == right) return finalAnswer;
        
        long long binary = findNone(root,0);
        return finalAnswer + calculateBinary(binary);
    }

    int depthCountLeft(TreeNode* root, int depth){
        if(root == nullptr) return depth;

        return depthCountLeft(root->left,depth+1);
    }

    int depthCountRight(TreeNode* root, int depth){
        if(root == nullptr) return depth;

        return depthCountRight(root->right,depth+1);
    }

    long long findNone(TreeNode* root, long long index){
        if(root == nullptr) return index;
        
        int left = depthCountLeft(root->left,0);
        int right = depthCountLeft(root->right,0);
        if(left > right){
            index *= 10;
            index += 0;
            return findNone(root->left,index);
        }
        else if(left == 0 && left == right){
            return index;
        }
        else{
            index *= 10;
            index += 1;
            return findNone(root->right,index);
        }
    }

    int calculateBinary(long long binary){
        int temp = 0;
        int finalAnswer = 0;
        while(binary > 0){
            finalAnswer += pow(2,temp) * (binary % 10);
            binary /= 10;
            temp++;
        }

        return finalAnswer + 1;
    }

};