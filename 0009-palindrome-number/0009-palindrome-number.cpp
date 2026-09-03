class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        
        string temp = to_string(x);
        for(int i = 0;i < temp.size()/2;i++){
            if(temp[i] != temp[temp.size()-1-i]) return false;
        }

        return true;
    }
};