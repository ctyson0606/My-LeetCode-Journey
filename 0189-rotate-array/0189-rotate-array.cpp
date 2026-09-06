class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        reverse(nums,0,n-1);
        reverse(nums,0,k-1);
        reverse(nums,k,n-1);
    }

    void reverse(vector<int>& nums, int startIdx, int endIdx){
        while(startIdx < endIdx){
            swap(nums[startIdx],nums[endIdx]);
            startIdx++;
            endIdx--;
        }
    }
};