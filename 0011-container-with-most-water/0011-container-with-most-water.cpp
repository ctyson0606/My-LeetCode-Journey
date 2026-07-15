class Solution {
public:
    int maxArea(vector<int>& height) {
        int max;
        int i = 0;
        int j = height.size()-1;
        if(height[i] > height[j]){
            max = height[j] * (j-i); 
        }
        else{
            max = height[i] * (j-i);
        }
        while(j > i){
            if(height[i] > height[j]){
                if(max < height[j] * (j-i)){
                    max = height[j] * (j-i); 
                }
                j--;
                
            }
            else{
                if(max < height[i] * (j-i)){
                    max = height[i] * (j-i); 
                }
                i++;
            }
        }
        return max;
    }
};