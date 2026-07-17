class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int count = 0;
        int front = 0;
        int back = 0;
        int temp = nums[0];
        bool first = true;;
        if(temp >= target){
            return 1;
        }
        while(back < nums.size()){
            if(temp >= target && back <= front){
                if(front-back+1 < count || first){
                    count = front-back+1;
                    first = false;
                }
                temp -= nums[back];
                back++;
            }
            else{
                if(front == nums.size()-1){
                    break;
                }
                front++;
                temp += nums[front];
            }
        }
        return count;
    }
};