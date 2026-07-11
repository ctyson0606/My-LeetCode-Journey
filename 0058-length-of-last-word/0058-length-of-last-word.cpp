class Solution {
public:
    int lengthOfLastWord(string s) {
        bool checkWord = false;
        int end;
        int start;
        for(int i = s.size()-1;i > -1;i--){
            if(s[i] != ' ' && !checkWord){
                checkWord = true;
                end = i;
            }
            if(checkWord && s[i] == ' '){
                start = i;
                break;
            }
            if(i == 0){
                start = -1;
                break;
            }
        }
        return end-start;
    }
};