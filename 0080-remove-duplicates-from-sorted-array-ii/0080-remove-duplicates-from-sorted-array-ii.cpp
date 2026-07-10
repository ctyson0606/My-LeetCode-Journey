class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // Version 1
        /*
        int i = 1;
        int copy = nums[0];
        int count = 1;
        while (i < nums.size()){
            if(nums[i] == copy){
                count++;
                if(count > 2){
                    nums.erase(nums.begin()+i);
                }
                else{
                    i++;
                }
            }
            else{
                copy = nums[i];
                count = 1;
                i++;
            }
        }
        return nums.size();
        */


        // Version 2
        int copy = nums[0];
        int count = 1;
        int repeat = -1;
        int CountRepeat = 0;

        for(int i = 1; i < nums.size() ; i++){
            if(nums[i] == copy){
                count++;
                if(count > 2){
                    CountRepeat++;
                    if(count == 3 && repeat == -1){
                        repeat = i;
                    }
                }
                else{
                    if(repeat != -1){
                        nums[repeat] = copy;
                        repeat++;  
                    }
                }
            }
            else{
                copy = nums[i];
                count = 1;
                if(repeat != -1){
                    nums[repeat] = copy;
                    repeat++;  
                }
            }
        }
        return nums.size() - CountRepeat;
    }
    
};