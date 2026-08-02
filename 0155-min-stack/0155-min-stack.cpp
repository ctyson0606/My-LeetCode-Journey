class MinStack {
private:
    vector<int> temp;
    vector<int> minNum;
public:
    MinStack() {
        
    }
    
    void push(int value) {
        if(minNum.size() == 0){
            minNum.push_back(value);
        }
        else if(*(minNum.end()-1) >= value){
            minNum.push_back(value);
        }
        temp.push_back(value);
    }
    
    void pop() {
        if(minNum.size() != 0 && *(minNum.end()-1) == *(temp.end()-1)){
            minNum.pop_back();
        }
        temp.pop_back();
    }
    
    int top() {
        return *(temp.end()-1);
    }
    
    int getMin() {
        return *(minNum.end()-1);
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */