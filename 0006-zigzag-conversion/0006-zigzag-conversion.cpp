class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1 || numRows >= s.size()){
            return s;
        }
        int midNum = numRows - 2;
        vector<vector<char>> fixed(numRows);
        int i = 0;
        int j = 0;
        bool countDown = false;
        int count = midNum;
        int tempNum;
        bool num = true;
        while(i < s.size()){
            if(!countDown){
                fixed[j].push_back(s[i]);
                i++;
                if(j == numRows-1){
                    countDown = true;
                    j--;
                }
                else{
                    j++;
                }
            }
            else{
                if(j != 0){
                    fixed[j].push_back(s[i]);
                    i++;
                    count--;
                    j--;
                }
                else{
                    countDown = false;
                }
            }
        }
        
        string finalAnswer;
        int a = 0;
        int b = 0;
        while(true){
            if(a == fixed.size()){
                break;
            }

            finalAnswer = finalAnswer + fixed[a][b];
            b++;

           if(b == fixed[a].size()){
                a++;
                b = 0;
            }

        }
        return finalAnswer;

    }
};