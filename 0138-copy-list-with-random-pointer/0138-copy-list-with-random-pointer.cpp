/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        vector<Node*> tempNew;
        unordered_map<Node*,int> record;
        Node* temp = head;
        int Size = 0;

        if(temp == nullptr){
            return nullptr;
        }
        
        while(true){
            if(temp == nullptr) break;

            Node* node = new Node(temp->val);
            record[temp] = Size;
            tempNew.push_back(node);
            temp = temp->next;
            Size++;
        }

        temp = head;
        for(int i = 0;i < Size;i++){
            if(i != Size-1){
                tempNew[i]->next = tempNew[i+1];
            }
            else{
                tempNew[i]->next = nullptr;
            }
            if(temp->random != nullptr){
                tempNew[i]->random = tempNew[record[temp->random]];
            }
            else{
                tempNew[i]->random = nullptr;
            }
            temp = temp->next;
        }

        return tempNew[0];
    }
};