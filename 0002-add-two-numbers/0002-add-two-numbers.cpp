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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int> temp1Ans;
        vector<int> temp2Ans;
        ListNode* temp1 = l1;
        bool temp1b = true;
        bool temp2b = true;
        ListNode* temp2 = l2;
        while(temp1b || temp2b){
            if(temp1b) temp1Ans.push_back(temp1->val);
            if(temp2b) temp2Ans.push_back(temp2->val);

            if(temp1b && temp1->next != nullptr){
                temp1 = temp1->next;
            }
            else if(temp1b){
                temp1b = false;
            }

            if(temp2b && temp2->next != nullptr){
                temp2 = temp2->next;
            }
            else if(temp2b){
                temp2b = false;
            }
        }
        vector<int> tempAnswer;
        int a;
        int b;
        temp1b = true;
        temp2b = true;
        int i  = 0;
        int temp = 0;
        while(temp1b || temp2b){
            if(temp1b){
                a = temp1Ans[i];
            }
            else{
                a = 0;
            }

            if(temp2b){
                b = temp2Ans[i];
            }
            else{
                b = 0;
            }

            temp += (a+b);
            tempAnswer.push_back(temp%10);
            temp /= 10;
            i++;

            if(i == temp1Ans.size()) temp1b = false;
            if(i == temp2Ans.size()) temp2b = false;

            if(!temp1b && !temp2b && temp != 0){
                tempAnswer.push_back(temp);
            }
        }

        ListNode* h = nullptr;
        for(int j  = tempAnswer.size()-1; j > -1;j--){
            ListNode* node = new ListNode(tempAnswer[j],h);
            h = node;
        }
        
        return h;
        
    }
};