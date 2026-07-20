class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char,string> recordPattern;
        unordered_map<string,char> recordS;
        int i = 0;
        int end = 0;
        int front = 0;
        int count = 0;
        while(front < s.size()){
            if(front == s.size()-1){
                string temp = s.substr(end,front-end+1);
                if(recordPattern.find(pattern[i]) == recordPattern.end() && recordS.find(temp) == recordS.end()){
                    recordPattern[pattern[i]] = temp;
                    recordS[temp] = pattern[i];
                }
                else{
                    if(recordPattern[pattern[i]] != temp || recordS[temp] != pattern[i]){
                        return false;
                    }
                }
                front++;
                i++;
            }
            else if(s[front] == ' '){
                string temp = s.substr(end,front-end);
                if(recordPattern.find(pattern[i]) == recordPattern.end() && recordS.find(temp) == recordS.end()){
                    recordPattern[pattern[i]] = temp;
                    recordS[temp] = pattern[i];
                }
                else{
                    if(recordPattern[pattern[i]] != temp || recordS[temp] != pattern[i]){
                        return false;
                    }
                }
                end = front + 1;
                front += 1;
                i++;
                count++;
            }
            else{
                front++;
            }
        }
        if(i != pattern.size()){
            return false;
        }
        return true;
        

    }
};