class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> testBoard = board;
        int m = board.size();
        int n = board[0].size();
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size() ;j++){
                board[i][j] = check(testBoard,i,j,board[i][j]);
            }
        }

        
    }

    int check(vector<vector<int>>& testBoard,int i,int j,int original){
        int oneCount = 0;
        int zeroCount = 0;
        int maxRow = i+1;
        int maxColumn = j+1;
        i--;
        j--;
        while(true){
            if(i < 0 || i >= testBoard.size() || j < 0 || j >= testBoard[0].size() || (i == maxRow-1 && j == maxColumn - 1));

            else if(testBoard[i][j] == 0){
                zeroCount++;
            }
            else{
                oneCount++;
            }
            j++;
            if(j == maxColumn+1){
                i++;
                j =  maxColumn-2;
            }
            if(i == maxRow+1){
                break;
            }
        }
        
        if(testBoard[maxRow-1][maxColumn-1] == 1){
            if(oneCount < 2){
                return 0;
            }
            else if(oneCount == 2|| oneCount == 3){
                return 1;
            }
            else if(oneCount > 3){
                return 0;
            }
        }
        else{
            if(oneCount == 3){
                return 1;
            }
        }

        return original;
    }
};