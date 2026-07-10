class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int> copy;
        int num = nums[0];
        copy.push_back(nums[0]);
        for(int i = 1; i < nums.size() ; i++){
            if(num != nums[i]){
                copy.push_back(nums[i]);
                num = nums[i];
            }
        }
        nums = copy;
        return copy.size();
    }
};