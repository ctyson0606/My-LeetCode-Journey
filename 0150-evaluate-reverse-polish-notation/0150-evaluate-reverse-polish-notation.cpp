class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        unordered_set<string> record = {
            {"+"},{"-"},{"*"},{"/"}
        };
        vector<int> temp;
        for(int i = 0;i < tokens.size();i++){
            if(record.find(tokens[i]) == record.end()){
                temp.push_back(stoi(tokens[i]));
            }
            else{
                int b = *(temp.end()-1);
                temp.pop_back();
                int a = *(temp.end()-1);
                temp.pop_back();
                if(tokens[i] == "+"){
                    temp.push_back(a+b);
                }
                else if(tokens[i] == "-"){
                    temp.push_back(a-b);
                }
                else if(tokens[i] == "*"){
                    temp.push_back(a*b);
                }
                else if(tokens[i] == "/"){
                    temp.push_back(a/b);
                }
            }
        }

        return temp[0];
    }
};