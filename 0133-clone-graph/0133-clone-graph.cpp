/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
private:
    unordered_map<int,Node*> record;
public:
    Node* cloneGraph(Node* node) {
        return clone(node);
    }

    Node* MakeNewNode(Node* node){
        if(record.find(node->val) != record.end()){
            return record[node->val];
        }
        else{
            Node* temp = new Node(node->val);
            record[node->val] = temp;
            return temp;
        }
    }
    
    Node* clone(Node* node){
        if(node == nullptr) return nullptr;

        Node* temp = MakeNewNode(node);
        for(int i = 0; i < node->neighbors.size();i++){
            if(record.find(node->neighbors[i]->val) == record.end()){
                temp->neighbors.push_back(clone(node->neighbors[i]));
            }
            else{
                temp->neighbors.push_back(record[node->neighbors[i]->val]);
            }
        }

        return temp;
    }
};