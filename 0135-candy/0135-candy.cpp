class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> leftranking;
        leftranking.push_back(1);
        for(int i = 1;i < ratings.size() ; i++){
            if(ratings[i] > ratings[i-1]){
                leftranking.push_back(leftranking[i-1] + 1);
            }
            else{
                leftranking.push_back(1);
            }
        }
        vector<int> rightranking(leftranking.size(),1);
        for(int i = ratings.size()-2;i > -1 ; i--){
            if(ratings[i] > ratings[i+1]){
                rightranking[i] = rightranking[i+1] + 1;
            }
        }
        int sum = 0;
        for(int i = 0; i < leftranking.size() ; i++){
            if(leftranking[i] > rightranking[i]){
                sum += leftranking[i];
            }
            else{
                sum += rightranking[i];
            }
        } 
        return sum;
    }
};