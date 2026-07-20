class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        bool containZeroRow = false;
        bool containZeroColumn = false;
        int row = 0;
        int column = 0;
        for(int i = 0;i < m;i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == 0 && !containZeroRow){
                    containZeroRow = true;
                    row = i;
                }

            }
            if(containZeroRow){
                break;
            }
        }
        for(int j = 0; j < n;j++){
            for(int i = 0; i < m;i++){
                if(matrix[i][j] == 0 && !containZeroColumn){
                    containZeroColumn = true;
                    column = j;
                }
            }
            if(containZeroColumn){
                break;
            }
        }

        if(containZeroColumn && containZeroRow){

            for(int i = 0;i < m;i++){
                for(int j = 0; j < n; j++){
                    if(matrix[i][j] == 0){
                        matrix[i][column] = 0;
                        matrix[row][j] = 0;
                    }
                }
            }

            
            for(int j = 0; j < n; j++){
                if(matrix[row][j] == 0){
                    for(int i = 0; i < m; i++){
                        if(i != row && j != column){
                            matrix[i][j] = 0;
                        }
                    }
                }
            }


            for(int i = 0; i < m; i++){
                if(matrix[i][column] == 0){
                    for(int j = 0; j < n; j++){
                        if(j != column && i != row){
                            matrix[i][j] = 0;
                        }
                    }
                }
            }
            for(int i = 0;i < m;i++){
                matrix[i][column] = 0;
            }
            for(int j = 0;j < n;j++){
                matrix[row][j] = 0;
            }
        }
        
    }
};