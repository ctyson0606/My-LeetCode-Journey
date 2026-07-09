class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        /*
        vector<int> answer;
        vector<int> left;
        vector<int> right;
        int leftSum = 1;
        int rightSum = 1;
        for(int i = 0;i<nums.size();i++){
            left.push_back(leftSum);
            leftSum *= nums[i];
        }
        for(int i = nums.size()-1; i > -1; i--){
            right.push_back(rightSum);
            rightSum *= nums[i];
        }
        for(int i = 0;i < nums.size() ; i++){
            answer.push_back(left[i] * right[nums.size()-1-i]);
        }
        return answer;
        */
        vector<int> answer;
        int sum = 1;
        for(int i = 0;i<nums.size();i++){
            answer.push_back(sum);
            sum *= nums[i];
        }
        sum = 1;
        for(int i = nums.size()-1; i > -1; i--){
            answer[i] *= sum;
            sum *= nums[i];
        }
        return answer;
    }
};