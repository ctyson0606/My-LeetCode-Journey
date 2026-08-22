/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
private:
    unordered_map<int,vector<Node*>> record;
    int max = 0;
public:
    Node* connect(Node* root) {
        max = TreeToOneD(root,0);
        int i = 0;
        while(i <= max){
            int j = 0;
            if(record[i].size() > 1){
                while(j < record[i].size()-1){
                    record[i][j]->next = record[i][j+1];
                    j++;
                }
            }
            i++;
        }
        return root;
    }

    int TreeToOneD(Node* root,int depth){
        if(root == nullptr) return depth-1;

        if(record.find(depth) == record.end()){
            record[depth] = {root}; 
        }
        else{
            record[depth].push_back(root);
        }

        int left = TreeToOneD(root->left,depth+1);
        int right = TreeToOneD(root->right,depth+1);

        if(max < left) max = left;
        if(max < right) max = right;

        return max;
    }


    
};