class Solution {
public:
    string reverseWords(string s) {
        string temp;
        string finalA;
        bool firstCheck = false;
        bool finalCheck = true;
        for(int i = 0;i < s.size(); i++){
            if(!firstCheck && s[i] != ' '){
                firstCheck = true;
                if(finalCheck){
                    finalCheck = false;
                }
                else{
                    finalA = " " + finalA;
                }
                temp = s[i];
            }
            else if(s[i] != ' '){
                temp = temp + s[i];
            }

            if((s[i] == ' ' && firstCheck) || (i == s.size()-1 && firstCheck)){
                firstCheck = false;
                finalA =  temp + finalA;
            }
        }
        return finalA;
    }
};