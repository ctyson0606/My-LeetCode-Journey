class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();

        if(n <= 2) return n;

        int idx = 2;
        int i = 2;
        while(i < n){
            if(nums[idx-2] != nums[i]){
                nums[idx] = nums[i];
                idx++;
            }
            i++;
        }

        return idx;
    }
};