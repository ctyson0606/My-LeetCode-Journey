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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* temp = head;
        int size = 0;
        while(temp != nullptr){
            size++;
            temp = temp->next;
        }
        if(size == 0 || size == 1) return head;
        k = k % size;
        for(int i = 0;i < k;i++){
            head = rotate(head);
        }

        return head;
    }

    ListNode* rotate(ListNode* head){
        ListNode* temp = head;

        while(temp->next->next != nullptr){
            temp = temp->next;
        }
        temp->next->next = head;
        head = temp->next;
        temp->next = nullptr;
        return head;
    }
};