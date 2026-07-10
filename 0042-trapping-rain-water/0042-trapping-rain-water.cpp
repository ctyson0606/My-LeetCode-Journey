class Solution {
public:
    int trap(vector<int>& height) {
        /*
        vector<int> left(height.size(),0);
        for(int i = 0; i < height.size()-1;i++){
            left[i+1] = height[i];
        }

        vector<int> right(height.size(),0);
        for(int i = 0; i < height.size()-1;i++){
            right[i] = height[i+1]; 
        }

        vector<int> answer;
        for(int i = 0; i < height.size();i++){
            if(left[i] > right[i]){
                answer.push_back(right[i]);
            }
            else{
                answer.push_back(left[i]);
            }
        }

        int sum = 0;
        for(int i = 0; i < height.size() ; i ++){
            if(answer[i] >= height[i]){
                sum += (answer[i] - height[i]);
            }
        }
        return sum;
        */

        /*
        unordered_map<int,int> indexVal;
        vector<int> index;
        vector<int> initIndex;
        bool increase = true;
        for(int i = 0; i < height.size(); i++){
            if(i == height.size()-1){
                if(indexVal.find(i-1) == indexVal.end()){
                    if(height[i] >= height[i-1]){
                        initIndex.push_back(i);
                        indexVal[i] = height[i];              
                    }
                }
            }
            
            else if(i == 0){
                if(height[i] > height[i+1]){
                    initIndex.push_back(i);
                    indexVal[i] = height[i];                   
                }

            }
            else if((height[i] >= height[i+1] && height[i] > height[i-1]) || (height[i] > height[i+1] && height[i] >= height[i-1])){
                initIndex.push_back(i);
                indexVal[i] = height[i];
            }
        }

        if(initIndex.size() >= 3){
            int i = 2;
            int j = 0;
            int max = indexVal[initIndex[1]];
            int maxIndex = 1;
            index.push_back(initIndex[0]);
        

            while(true){
                if(i == initIndex.size()-1){
                    index.push_back(initIndex[i]);
                    j = maxIndex;
                    i = j + 1;
                    max = 0;
                    continue;
                }
                if(j >= initIndex.size()-1){
                    break;
                }
                if(max < indexVal[initIndex[i]]){
                    max = indexVal[initIndex[i]];
                    maxIndex = initIndex[i];
                }
                i++;
            }
        }

        else{
            index = initIndex;
        }

        int h = 0;
        int min=0;
        int sum = 0;

        for(int i = index[0] ; i < height.size() ; i++){
            if(i == index[index.size()-1]){
                break;
            }
            if(index[h] == i){
                if(indexVal[index[h]] > indexVal[index[h+1]]){
                    min = indexVal[index[h+1]];
                }
                else{
                    min = indexVal[index[h]];
                }
                h++;
                continue;
            }
            sum += (min - height[i]);

        }

        return sum;
        */

        /*
        int h = 0;
        int min = 0;
        if(indexVal[index[1]] > indexVal[index[0]]){
            min = indexVal[index[0]];
        }
        else{
            min = indexVal[index[1]];
        }
        int sum = 0;
        for(int i = index[0]+1;i<height.size();i++){
            if(h+1 <= index.size()- 1 && i == index[h+1]){
                h++;
                if(indexVal[index[h+1]] > indexVal[index[h]]){
                    min = indexVal[index[h]];
                }
                else{
                    min = indexVal[index[h]];
                }
               
            }
            sum += (height[i] - min);
        }
        return sum;
        */
        vector<int> leftMax;
        vector<int> rightMax(height.size(),0);

        for(int i = 0; i < height.size(); i++){
            if(i == 0){
                leftMax.push_back(height[i]);
            }
            else{
                if(leftMax[i-1] < height[i]){
                    leftMax.push_back(height[i]);
                }
                else{
                    leftMax.push_back(leftMax[i-1]);
                }
            }
        }

        for(int i = height.size()-1; i > -1; i--){
            if(i == height.size()-1){
                rightMax[i] = height[i];
            }
            else{
                if(rightMax[i+1] < height[i]){
                    rightMax[i] = height[i];
                }
                else{
                    rightMax[i] = rightMax[i+1];
                }
            }
        }
        
        int sum = 0;
        for(int i = 0; i < height.size(); i++){
            if(leftMax[i] < rightMax[i]){
                if(leftMax[i] > height[i]){
                    sum += (leftMax[i] - height[i]);
                }
            }
            else{
                if(rightMax[i] > height[i]){
                    sum += (rightMax[i] - height[i]);
                }
            }
        }

        return sum;
        
    }
};