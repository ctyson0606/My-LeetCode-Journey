class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
            vector<int> newNum;
            int count = 0;
            int size = nums.size();
            for(int i = 0;i<nums.size();i++){
                if(nums[i] == val){
                    count++;
                }
                else{
                    newNum.push_back(nums[i]);
                }
            }
            nums = newNum;
            return size-count;
    }
};