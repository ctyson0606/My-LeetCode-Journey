class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int start = 0;
        int end = nums.size()-1;
        while(start <= end){
            int mid = (start + end) / 2;
            if ((mid + 1 == nums.size() || nums[mid] > nums[mid+1]) && (mid - 1 == -1 || nums[mid-1] < nums[mid])) return mid;

            if(nums[mid+1] > nums[mid]){
                start = mid + 1;
            }
            else{
                end = mid-1;
            }
        }
        return -1;
    }
};