/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        vector<int> original;
        vector<int> greater;
        if(head == nullptr || head->next == nullptr) return head;

        ListNode* temp = head;
        while(temp != nullptr){
            if(temp->val < x){
                original.push_back(temp->val);
            }
            else{
                greater.push_back(temp->val);
            }
            temp = temp->next;
        }

        temp = head;
        for(int i = 0;i < original.size();i++){
            temp->val = original[i];
            temp = temp->next;
        }

        for(int i = 0;i < greater.size();i++){
            temp->val = greater[i];
            temp = temp->next;
        }

        return head;

    }
};