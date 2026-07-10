class Solution {
public:
    int jump(vector<int>& nums) {
        
        int i = 0;
        int max = 0;
        int maxIndex = 0;
        int count = 0;
        while(true){
            max = 0;
            if(i >= nums.size()-1){
                return count;
            }
            if(nums.size() <= 2){
                return 1;
            }
            for(int j = i+1; j-i < nums[i]+1 ; j++){
                if(max <= nums[j] + j - i && j < nums.size()){
                    max = nums[j] + j - i;
                    maxIndex = j;
                }
                if(j == nums.size()-1){
                    count ++;
                    return count;
                }
            }
            count++;
            i = maxIndex;
        }
        


    }
};