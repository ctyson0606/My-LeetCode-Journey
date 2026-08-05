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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        /*
        ListNode* pre = nullptr;
        ListNode* temp = head;
        vector<ListNode*> tempAnswer;
        bool leftb = true;
        bool rightb = true;
        while(leftb || rightb){
            if(leftb && temp->val == left){
                leftb = false;
                tempAnswer.push_back(pre);
                tempAnswer.push_back(temp);
                tempAnswer.push_back(temp->next);
            }

            if(rightb && temp->val == right){
                rightb = false;
                tempAnswer.push_back(pre);
                tempAnswer.push_back(temp);
                tempAnswer.push_back(temp->next);
            }

            pre = temp;
            temp = temp->next;
        }

        tempAnswer[0]->next = tempAnswer[4];
        tempAnswer[1]->next
        */
        ListNode* temp = head;
        vector<ListNode*> tempAnswer;
        int size = 1;;
        while(size <= right){
            if(temp == nullptr) break;

            if(size >= left && size <= right){
                tempAnswer.push_back(temp);
            }

            temp = temp->next;
            size++;
        }

        for(int i = 0; i < tempAnswer.size()/2;i++){
            int a = tempAnswer[i]->val;
            tempAnswer[i]->val = tempAnswer[tempAnswer.size()-i-1]->val;
            tempAnswer[tempAnswer.size()-i-1]->val = a;
        }

        return head;
    }
};