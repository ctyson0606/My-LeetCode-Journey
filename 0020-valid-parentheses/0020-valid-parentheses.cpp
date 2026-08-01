class Solution {
public:
    bool isValid(string s) {
        if(s.size() % 2 != 0) return false;
        unordered_map<char,char> record = {
            {'(',')'},
            {'{','}'},
            {'[',']'},
        };

        unordered_map<char,char> recordX = {
            {')','('},
            {'}','{'},
            {']','['},
        };

        vector<char> temp;

        for(int i = 0; i < s.size();i++){
            if(record.find(s[i]) != record.end()){
                temp.push_back(s[i]);
             }
            else if(temp.size() == 0 || *(temp.end()-1) != recordX[s[i]]){
                return false;
            }
            else{
                temp.pop_back();
            }
        }

        if(temp.size() != 0) return false;

        
        return true;
    }
};