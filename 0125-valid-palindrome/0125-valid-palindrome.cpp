class Solution {
public:
    bool isPalindrome(string s) {
        /*
        string temp = "";
        for(int i = 0; i < s.size();i++){
            if((s[i] >= 97 && s[i] <= 122) || (s[i] >= 48 && s[i] <= 57)){
                temp = temp + s[i];
            }
            else if(s[i] >= 65 && s[i] <= 90){
                temp = temp + (char)(s[i]+32);
            }
        }

        for(int i = 0; i < temp.size();i++){
            if(temp[i] != temp[temp.size()-1-i]){
                return false;
            }
        }
        return true;
        */

        int i = 0;
        int j = s.size()-1;
        char temp1;
        char temp2;
        bool t1 = true;
        bool t2 = true;
        while(i < j){
            while(t1 && i < s.size()){
                if((s[i] >= 97 && s[i] <= 122) || (s[i] >= 48 && s[i] <= 57)){
                    temp1 = s[i];
                    t1 = false;
                }  
                else if(s[i] >= 65 && s[i] <= 90){
                    temp1 = (char)(s[i]+32);
                    t1 = false;
                }     
                i++;
            }
            while(t2 && j > -1){
                if((s[j] >= 97 && s[j] <= 122) || (s[j] >= 48 && s[j] <= 57)){
                    temp2 = s[j];
                    t2 = false;
                }  
                else if(s[j] >= 65 && s[j] <= 90){
                    temp2 = (char)(s[j]+32);
                    t2 = false;
                }       
                j--;           
            }
            t1 = true;
            t2 = true;
            if(temp1 != temp2){
                return false;
            }
        }
        return true;
    }
};