class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int,int> temp;
        while(true){
            calSquares(n);
            if(temp.find(n) == temp.end()){
                temp[n] = 1;
            }
            else{
                return false;
            }
            if(n == 1){
                return true;
            }
        }
    }

    void calSquares(int& n){
        int temp = 0;
        int answer = 0;
        while(n > 0){
            temp = n % 10;
            n /= 10;
            answer += (temp * temp);
        }
        n = answer;
    }
};