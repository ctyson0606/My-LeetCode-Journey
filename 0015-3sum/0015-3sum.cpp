class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        set<vector<int>> tempAnswer;
        /*
        int a = 0;
        int b = a+1;
        while(a < nums.size()-2){
            while(b < nums.size()-1){
                int tempIndex = binarySearch(b+1,(nums.size()-1),nums,(0-nums[a]-nums[b]));
                if(tempIndex > 0){
                    vector<int> temp = {nums[a],nums[tempIndex],nums[b]};
                    sort(temp.begin(), temp.end());
                    tempAnswer.insert(temp);
                }
                b++;

            }
            a++;
            b = a + 1;
        }
        */

        for(int i = 0; i < nums.size()-2;i++){
            for(int j = i+1; j < nums.size()-1;j++){
                int tempIndex = binarySearch(j+1,(nums.size()-1),nums,(0-nums[i]-nums[j]));
                if(tempIndex > 0){
                    vector<int> temp = {nums[i],nums[j],nums[tempIndex]};
                    //sort(temp.begin(), temp.end());
                    tempAnswer.insert(temp);
                }
            }
        }
        vector<vector<int>> answer(tempAnswer.begin(),tempAnswer.end());
        return answer;
    }

    int binarySearch(int low, int high, vector<int>& nums, int target){
        while(low <= high){
            int mid = (low + high) / 2;
            if(nums[mid] == target){
                return mid;
            }
            else if(target < nums[mid]){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return -1;
    }
};