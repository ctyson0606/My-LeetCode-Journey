class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int plus = 1;
        int i = digits.size()-1;
        while(plus != 0 && i >= 0){
            digits[i] += plus;
            if(digits[i] >= 10){
                digits[i] = digits[i] % 10;
            }
            else{
                plus = 0;
            }
            i--;
        }

        if(plus == 1) digits.insert(digits.begin(),plus);

        return digits;
    }
};