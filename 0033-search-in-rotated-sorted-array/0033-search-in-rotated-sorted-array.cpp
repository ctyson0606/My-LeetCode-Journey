class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size()-1;
        while(start <= end){
            int mid = ( end + start ) / 2;
            cout << mid << endl;
            if(nums[mid] == target) return mid;
            if(nums[mid] < nums[start]){
                if(nums[mid] < target){
                    if(nums[end] < target){
                        end = mid - 1;
                    }
                    else{
                        start = mid + 1;
                    }
                }
                else{
                    end = mid - 1;
                }
            }
            else{
                if(nums[mid] < target){
                    start = mid + 1;
                }
                else{
                    if(nums[start] > target){
                        start = mid + 1;
                    }
                    else{
                        end = mid - 1;
                    }
                }
            }
        }
        return -1;
    }
};