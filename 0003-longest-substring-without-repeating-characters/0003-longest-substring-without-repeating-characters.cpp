class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int front = 0;
        int back = 0;
        int count = 0;
        bool first = true;
        int temp;
        while(front < s.size()){
            temp = check(s,back,front,s[front]);
            if(temp == -1 || first){
                if(first || count < front-back+1){
                    count = front - back + 1;
                    first = false;
                }
                front++;
            }
            else{
                back = temp + 1;
            }
        }
        return count;

    }

    int check(string s, int back, int front, char target){
        for(int i = back; i < front;i++){
            if(s[i] == target){
                return i;
            }
        }
        return -1;
    }
};