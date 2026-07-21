class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        unordered_set<int> temp;
        temp.reserve(nums.size());
        unordered_set<int> record;
        record.reserve(nums.size());
        for(int i = 0;i < nums.size();i++){
            temp.insert(nums[i]);
        }

        int count = 0;
        int maxCount = 0;
        int i = 0;
        int num = nums[i]-1;
        bool con = false;
       
        while(i < nums.size()){
            if(temp.find(nums[i]-1) == temp.end() && !con && record.find(nums[i]) == record.end()){
                record.insert(nums[i]);
                con = true;
                count++;
                num = nums[i] + 1;
            }

            if(temp.find(num) != temp.end() && con){
                num++;
                count++;
            }
            else{
                if(maxCount < count){
                    maxCount = count;
                }
                count = 0;
                con = false;
                i++;
            }
        }

        return maxCount;

    }
};