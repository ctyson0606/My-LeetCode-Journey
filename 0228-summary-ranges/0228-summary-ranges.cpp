class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> answer;
        int i = 0;
        int end = 0;
        while(i < nums.size()){
            if(i != nums.size()-1 && nums[i+1] == nums[i] + 1){
                i++;
            }
            else{
                if(i == end){
                    answer.push_back(to_string(nums[i]));
                }
                else{
                    answer.push_back(to_string(nums[end]) + "->" + to_string(nums[i]));
                }
                end = i+1;
                i++;
            }
            if(i == nums.size()){
                break;
            }
        }
        return answer;
    }
};