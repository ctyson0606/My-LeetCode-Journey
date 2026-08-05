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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        vector<ListNode*> tempAnswer;
        ListNode* temp = head;
        while(temp != nullptr){
            tempAnswer.push_back(temp);
            temp = temp->next;
        }

        if(tempAnswer.size() == 1) return nullptr;

        ListNode* index;
        if(tempAnswer.size()-n+1 >= tempAnswer.size()){
            index = nullptr;
        }
        else{
            index = tempAnswer[tempAnswer.size()-n+1];
        }

        if(tempAnswer.size()-n-1 == -1) return tempAnswer[1];

        tempAnswer[tempAnswer.size()-n-1]->next = index;

        return head;
    }
};