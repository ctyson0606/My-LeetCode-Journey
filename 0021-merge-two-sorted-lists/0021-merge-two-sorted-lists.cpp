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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        bool temp1 = true;
        bool temp2 = true;
        vector<int> tempAnswer;
        int temp;
        while(temp1 || temp2){
            if(list1 == nullptr) temp1 = false;
            if(list2 == nullptr) temp2 = false;

            if(temp2 && (!temp1 || list1->val > list2->val)){
                temp = list2->val;
                list2 = list2->next;
            }
            else if(temp1){
                temp = list1->val;
                list1 = list1->next;
            }

            if(temp1 || temp2) tempAnswer.push_back(temp);
        }

        ListNode* h = nullptr;
        for(int i = tempAnswer.size()-1;i > -1;i--){
            ListNode* node = new ListNode(tempAnswer[i],h);
            h = node;
        }

        return h;
    }
};