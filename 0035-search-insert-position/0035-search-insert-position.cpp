class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(target > nums.back()) return nums.size();
        if(target < nums.front()) return 0;
        int start = 0;
        int end = nums.size()-1;
        int mid;
        while(start <= end){
            cout << start << " " << end << endl;
            if(start + 1 == end && target > nums[start] && target < nums[end]) return end;
            mid = (end + start) / 2;
            if(target == nums[mid]){
                return mid;
            }
            else if(target > nums[mid]){
                start = mid+1;
            }
            else{
                end = mid - 1;
            }
        }
        if(nums[mid] < target) return mid+1;
        return mid;
    }
};