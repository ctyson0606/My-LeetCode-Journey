class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> temp;
        vector<int> temp1;
        int i = 0;
        int j = 0;
        if(nums.size() >= k){
        temp.insert(temp.begin(),nums.end()-k,nums.end());
        temp.insert(temp.end(),nums.begin(),nums.end()-k);
        nums = temp;
        }
        else{
            while(i < k){
                temp.insert(temp.begin(),*(nums.end()-1-j));
                i++;
                j++;
                if(j >= nums.size()){
                    j = 0;
                }

            }
            temp1.insert(temp1.begin(), temp.begin(), temp.begin()+nums.size());
            nums = temp1;
        }
    }
};