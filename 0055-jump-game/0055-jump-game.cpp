class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<int> Index;
        bool IsZero = false;
        if(nums.size() == 1) return true;
        for(int i = 0; i < nums.size();i++){
            if(nums[i] == 0 && !(i == nums.size()-1)){
                IsZero = true;
                Index.push_back(i);
            }
        }
        if(!IsZero) return true;
        for(int i = 0; i < Index.size() ; i++){
            bool CheckEnough = false;
            for(int j = 0; j < Index[i] ; j++){
                if(Index[i]+1-j <= nums[j]){
                    CheckEnough = true;
                }
            }
            if(!CheckEnough) return false;
        }

        return true;


    }
};