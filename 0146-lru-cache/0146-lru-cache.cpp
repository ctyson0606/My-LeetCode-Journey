class LRUCache {
private:
    struct ListNode{
        int key;
        int val;
        ListNode* next;
        ListNode* pre;
        ListNode() : key(0), val(0), next(nullptr){}
        ListNode(int x, int y) : key(x), val(y), next(nullptr){}
    };
    unordered_map<int,ListNode*> record;
    ListNode* temp;
    ListNode* head;
    int used = 0;
    int size;
public:
    LRUCache(int capacity) {
        size = capacity;
    }
    
    int get(int key) {
        if(record.find(key) == record.end()) return -1;

        ListNode* node = record[key];
        if(node == temp || size == 1) return node->val;

        if(node == head){
            node->next->pre = nullptr;
            head = node->next;
        }
        else{
            node->pre->next = node->next;
            node->next->pre = node->pre;
        }
        temp->next = node;
        node->pre = temp;
        node->next = nullptr;
        temp = node;
        return record[key]->val;
    }
    
    void put(int key, int value) {
        if(size != 1 || used == 0){
            if(used >= size && record.find(key) == record.end()){
                head->next->pre = nullptr;
                record.erase(head->key);
                ListNode* test = head;
                head = head->next;
                delete test;
            }
            if(used == 0){
                ListNode* node = new ListNode(key,value);
                record[key] = node;
                temp = node;
                head = temp;
                used++;
            }
            else{
                if(record.find(key) == record.end()){
                    ListNode* node = new ListNode(key,value);
                    record[key] = node;
                    temp->next = node;
                    node->pre = temp;
                    temp = node;
                    used++;
                }
                else{
                    ListNode* node = record[key];
                    node->val = value;
                    if(node != temp){
                        if(node != head){
                            node->pre->next = node->next;
                            node->next->pre = node->pre;
                        }
                        else{
                            node->next->pre = nullptr;
                            head = node->next;
                        }
                        temp->next = node;
                        node->pre = temp;
                        node->next = nullptr;
                        temp = node;
                    } 
                }
            }
        }
        else{
            record.erase(temp->key);
            record[key] = temp;
            temp->val = value;
            temp->key = key;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */