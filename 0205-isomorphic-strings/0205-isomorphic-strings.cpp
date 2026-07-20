class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> recordS;
        unordered_map<char,char> recordT;
        for(int i = 0;i < s.size();i++){
            if(recordS.find(s[i]) == recordS.end() && recordT.find(t[i]) == recordT.end()){
                recordS[s[i]] = t[i];
                recordT[t[i]] = s[i];
            }
            else{
                if(recordS[s[i]] != t[i] || recordT[t[i]] != s[i]){
                    return false;
                }
            }
        }

        return true;
    }
};