class Solution {
public:
    int findMin(vector<int>& nums) {
        int start = 0;
        int end = nums.size()-1;
        int min = 5001;
        while(start <= end){
            int mid = (start + end) / 2;
            if(min > nums[mid]) min = nums[mid];

            if(nums[mid] > nums[end]){
                start = mid + 1;
            }
            else{
                end = mid - 1;
            }
        }
        return min;
    }
};