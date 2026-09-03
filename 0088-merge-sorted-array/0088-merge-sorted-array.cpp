class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(n == 0){
            return;
        } 
        
        int oneIdx = m-1;
        int twoIdx = n-1;
        
        for(int i = m + n -1; i > -1;i--){
            if(twoIdx < 0){
                return;
            }
            else if(oneIdx < 0){
                nums1[i] = nums2[twoIdx];
                twoIdx--;
            }
            else{
                if(nums1[oneIdx] < nums2[twoIdx]){
                    nums1[i] = nums2[twoIdx];
                    twoIdx--;
                }
                else{
                    nums1[i] = nums1[oneIdx];
                    oneIdx--;
                }
            }
        }
    }
};