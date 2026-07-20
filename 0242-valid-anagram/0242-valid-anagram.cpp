class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> record;

        if(s.size() != t.size()){
            return false;
        }
        
        for(int i = 0;i < s.size();i++){
            if(record.find(s[i]) == record.end()){
                record[s[i]] = 1;
            }
            else{
                record[s[i]]++;
            }
        }

        for(int i = 0 ;i < t.size() ;i++){
            if(record.find(t[i]) != record.end()){
                if(record[t[i]] > 0){
                    record[t[i]]--;
                }
                else{
                    return false;
                }
            }
            else{
                return false;
            }
        }

        return true;
    }
};