class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int start = 0;
        int end = matrix.size() * matrix[0].size() - 1;
        while(start <= end){
            int mid = (end + start) / 2;
            int j = mid % matrix[0].size();
            int i = mid / matrix[0].size();
            if(matrix[i][j] == target) return true;

            if(matrix[i][j] < target){
                start = mid + 1;
            } 
            else{
                end = mid - 1;
            }
        }
        return false;
    }
};