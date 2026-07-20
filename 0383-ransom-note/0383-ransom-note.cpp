class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> record;
        for(int i = 0; i < magazine.size();i++){
            if(record.find(magazine[i]) != record.end()){
                record[magazine[i]]++;
            }
            else{
                record[magazine[i]] = 1;
            }
        }

        for(int i = 0; i < ransomNote.size();i++){
            if(record.find(ransomNote[i]) != record.end()){
                if(record[ransomNote[i]] > 0){
                    record[ransomNote[i]]--;
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