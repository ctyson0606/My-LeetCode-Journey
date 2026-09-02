class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        buildMaxMap(nums);
        for(int i = 0;i < k-1;i++){
            swap(nums[0],nums[nums.size()-1]);
            nums.pop_back();
            heapify(nums, 0,nums.size());
        }

        return nums[0];
    }

    void heapify(vector<int>& nums, int idx, int size){
        int maxIdx = idx;

        if(size > idx * 2 + 1 && nums[idx*2+1] > nums[maxIdx]){
            maxIdx = idx * 2 + 1;
        }

        if(size > idx * 2 + 2 && nums[idx*2+2] > nums[maxIdx]){
            maxIdx = idx * 2 + 2;
        }

        if(maxIdx != idx){
            swap(nums[idx], nums[maxIdx]);
            heapify(nums, maxIdx,size);
        }
    }

    void buildMaxMap(vector<int>& nums){
        int size = nums.size();
        for(int i = size - 1;i > -1;i--){
            heapify(nums,i,size);
        }
    }
};