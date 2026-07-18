class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> answer;
        int m = matrix.size();
        int n = matrix[0].size();
        int h = 0;
        int k = -1;
        int i = 0;
        int j = 0;
        bool first = false;
        while(true){
            while(j < n){
                if(first){
                    first = false;
                }
                else{
                    answer.push_back(matrix[i][j]); 
                }
                j++;
            }
            j--;
            n--;;
            first = true;

            if(i+1 >= m){
                break;
            }

            while(i < m){
                if(first){
                    first = false;
                }
                else{
                    answer.push_back(matrix[i][j]);
                }
                i++;
                
            }
            i--;
            m--;
            first = true;
            
            if(j-1 <= k){
                break;
            }

            while(j > k){
                if(first){
                    first = false;
                }
                else{
                    answer.push_back(matrix[i][j]);   
                }
                j--;
            }
            j++;
            k++;
            first = true;
 
            if(i-1 <= h){
                break;
            }

            while(i > h){
                if(first){
                    first = false;
                }
                else{
                    answer.push_back(matrix[i][j]);
                }
                i--;
            }
            i++;
            h++;
            first = true;

            if(j+1 >= n){
                break;
            }
        }
        return answer;
    }
};