class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        /*
        int i = 0;
        int j = 0;
        while(i < nums.size()-1){
            j = i + 1;
            while(j < i+k+1 && j < nums.size()){
                if(nums[i] == nums[j]){
                    return true;
                }
                j++;
            }
            i++;
        }

        return false;
        */
        map<int,int> tempNum;
        for(int i = 0; i < nums.size(); i++){
            if(tempNum.find(nums[i]) == tempNum.end()){
                tempNum[nums[i]] = i;
            }
            else{
                if(i - tempNum[nums[i]] <= k){
                    return true;
                }
                tempNum[nums[i]] = i;
            }
        }

        return false;
    }
};