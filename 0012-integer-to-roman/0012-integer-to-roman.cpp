class Solution {
public:
    string intToRoman(int num) {
        unordered_map<int,char> intToRoman = { 
            {1, 'I'},
            {5, 'V'},
            {10, 'X'},
            {50, 'L'},
            {100, 'C'},
            {500, 'D'},
            {1000, 'M'}
        };

        unordered_map<int, string> fourNineRoman = {
            {4,"IV"},
            {9,"IX"},
            {40,"XL"},
            {90,"XC"},
            {400,"CD"},
            {900,"CM"}
        };
        vector<int> roValue = {1,5,10,50,100,500,1000};
        vector<int> power = {1,10,100,1000};
        int Lnum;
        string roman;
        int powI = 0;
        int h;
        string temp;
        while(num > 0){
            temp = "";
            h = roValue.size()-1;
            Lnum = num % 10;
            num = num / 10; 
            if(Lnum == 4 || Lnum == 9){
                roman = fourNineRoman[Lnum * power[powI]] + roman;
            }
            else{
                while(Lnum != 0 && h > -1){
                    if((Lnum * power[powI]) >= roValue[h]){
                        temp = temp + intToRoman[roValue[h]];
                        Lnum = Lnum  - roValue[h] / power[powI];
                    }
                    else{
                        h--;
                    }
                }
                roman = temp + roman;
            }
            powI++;
        }
        return roman;
    }
};