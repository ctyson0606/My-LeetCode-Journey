class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0 ){
            return "";
        }

        if(strs.size() == 1){
            return strs[0];
        }

        string finalString = "";
        char tempString;
        int h = 0;
        int i = 0;
        while(true){
            if(i == 0){
                tempString = strs[i][h];
            }
            if(i == strs.size()){
                i = 0;
                h++;
                finalString = finalString + tempString;
                continue;
            }
            if(h >= strs[i].size()){
                break;
            }
            if(strs[i].size() == 0){
                return "";
            }

            if(tempString != strs[i][h]){
                break;
            }
            i++;
        }
        return finalString;
    }
};