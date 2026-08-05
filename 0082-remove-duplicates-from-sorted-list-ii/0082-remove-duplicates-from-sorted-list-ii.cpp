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
    ListNode* deleteDuplicates(ListNode* head) {
        vector<ListNode*> tempAnswer;
        ListNode* temp = head;
        ListNode* before = nullptr;
        int count = 0;

        if(temp == nullptr) return temp;

        while(temp != nullptr){
            if(before != nullptr && temp->val != before->val){
                if(count == 1){
                    cout << count << endl;
                    tempAnswer.push_back(before);
                }
                count = 1;
            }
            else{
                count++;
            }
            
            before = temp;
            temp = temp->next;
            if(temp == nullptr && count == 1){
                tempAnswer.push_back(before);
            }
        } 

        if(tempAnswer.size()==0) return nullptr;
        for(int i = 0; i < tempAnswer.size();i++){
            if(i == tempAnswer.size()-1){
                tempAnswer[i]->next = nullptr;
            }
            else{
                tempAnswer[i]->next = tempAnswer[i+1];
            }
        }

        return tempAnswer[0];
    }
};