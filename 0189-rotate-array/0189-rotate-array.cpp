class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> temp(n);
        k = k % n;
        if(k == 0) return;
        if(n <= 1) return;

        int idx = n - k;
        int i = 0;
        temp[i] = nums[idx];
        i++;
        idx = (idx+1) % n;
        while(idx != n-k){
            temp[i] = nums[idx];
            i++;
            idx = (idx+1) % n;
        }

        nums = temp;
    }
};