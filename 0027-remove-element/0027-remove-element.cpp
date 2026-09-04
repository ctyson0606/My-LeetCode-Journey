class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int startIdx = 0;
        int endIdx = nums.size()-1;
        int count = 0;
        while(startIdx <= endIdx){
            if(nums[startIdx] == val){
                swap(nums[startIdx],nums[endIdx]);
                endIdx--;
                count++;
            }
            else{
                startIdx++;
            }
        }

        return nums.size()-count;
    }
};