class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> romanInteger = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
        };

        int sum = 0;
        for(int i = s.size()-1;i > -1;i--){
            if(i != s.size()-1){
                if(s[i+1] == 'X' || s[i+1] == 'V'){
                    if(s[i] == 'I'){
                        sum -= romanInteger[s[i]];
                        continue;
                    }
                }
                else if(s[i+1] == 'L' || s[i+1] == 'C'){
                    if(s[i] == 'X'){
                        sum -= romanInteger[s[i]];
                        continue;
                    }  
                }
                else if(s[i+1] == 'D' || s[i+1] == 'M'){
                    if(s[i] == 'C'){
                        sum -= romanInteger[s[i]];
                        continue;
                    }  
                }
            }
            sum += romanInteger[s[i]];
        }

        return sum;
    }
};