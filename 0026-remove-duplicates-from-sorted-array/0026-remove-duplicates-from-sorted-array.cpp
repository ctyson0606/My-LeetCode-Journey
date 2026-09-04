class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();
        int idx = 1;
        int i = 1;
        while(i < size){
            if(nums[i] != nums[i-1]){
                nums[idx] = nums[i];
                idx++;
            }
            i++;
        }

        return idx;
    }
};