class Solution {
public:
    int hIndex(vector<int>& citations) {
        int HIndex = 0;
        int count = 0;
        for(int i = 0;i < citations.size()+1;i++){
            count = 0;
            for(int j = 0;j < citations.size();j++){
                if(citations[j] >= i){
                    count++;
                }
            }
            if(count >= i){
                HIndex = i;
            }
        }
        return HIndex;
    }
};