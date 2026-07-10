class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int size = nums.size();
        std::unordered_map<int,int> amount;
        for(int i = 0;i < size;i ++){
            if(amount.contains(nums[i])){
                amount[nums[i]] += 1;
            }
            else{
                amount[nums[i]] = 1;
            }
            if(amount[nums[i]] > (size/2)){
                return nums[i];
            }
        }
        return -1;
    }
};