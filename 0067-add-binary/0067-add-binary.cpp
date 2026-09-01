class Solution {
public:
    string addBinary(string a, string b) {
        int size;
        if(a.size() > b.size()){
            size = a.size();
        }
        else{
            size = b.size();
        }
        string finalAnswer;
        bool test = false;
        char lastRound = '0';
        for(int i = 0;i < size;i++){
            char tempA;
            char tempB;
            if(i < a.size()){
                tempA = a[a.size()-1-i];
            }
            else{
                tempA = '0';
            }

            if(i < b.size()){
                tempB = b[b.size()-1-i];
            }
            else{
                tempB = '0';
            }

            if(tempA == '0' && tempB == '0'){
                if(lastRound == '1'){
                    finalAnswer.push_back('1');
                }
                else{
                    finalAnswer.push_back('0');
                }
                test = false;
                lastRound = '0';
            }
            else if(tempA == '0' || tempB == '0'){
                if(lastRound == '1'){
                    finalAnswer.push_back('0');
                    test = true;
                    lastRound = '1';
                }
                else{
                    finalAnswer.push_back('1');
                    test = false;
                    lastRound = '0';
                }
            }
            else{
                if(lastRound == '1'){
                    finalAnswer.push_back('1');
                }
                else{
                    finalAnswer.push_back('0');
                }
                test = true;
                lastRound = '1';
            }
        }
        if(test) finalAnswer.push_back('1');

        for(int i = 0; i < finalAnswer.size() / 2; i++){
            swap(finalAnswer[i],finalAnswer[finalAnswer.size()-1-i]);
        }

        return finalAnswer;
    }

};