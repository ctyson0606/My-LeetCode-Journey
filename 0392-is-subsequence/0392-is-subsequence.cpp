class Solution {
public:
    bool isSubsequence(string s, string t) {
        int h = 0;
        int k = 0;
        int index;
        if(s.size() == 0){
            return true;
        }
        if(t.size() == 0){
            return false;
        }
        while(k < t.size()){
            if(s[h] == t[k]){
                if(h == s.size()-1){
                    return true;
                }
                h++;
            }
            k++;
        }
        return false;
    }
};