/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    unordered_set<ListNode*> record;
public:
    bool hasCycle(ListNode *head) {
        if(head == nullptr) return false;
        ListNode* temp = head;
        while(true){
            if(record.find(temp) != record.end()){
                return true;
            }
            else{
                record.insert(temp);
            }

            if(temp->next == nullptr){
                return false;
            }

            temp = temp->next;
        }
    }
};