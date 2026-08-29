class Solution {
public:
    void solve(vector<vector<char>>& board) {
        for(int i = 1;i < board.size()-1;i++){
            for(int j = 1;j < board[i].size()-1;j++){
                ChangeP(board,i,j);
            }
        }
    }

    void ChangePoint(vector<vector<char>>& board,int i, int j){
        if(board.size() != 0 && i > 0 && i < board.size()-1 && j > 0 && j < board[i].size()-1){
            if(board[i][j] == 'O'){
                board[i][j] = 'X';

                ChangePoint(board,i-1,j);
                ChangePoint(board,i+1,j);
                ChangePoint(board,i,j-1);
                ChangePoint(board,i,j+1);
            }
        }
        else if(board.size() > 0 && ((i == 0 || i == board.size()-1) || (j == 0 || j == board[i].size()-1))){
            if(board[i][j] == 'O') board = vector<vector<char>>(0);
        }
    }

    void ChangeP(vector<vector<char>>& board,int i,int j){
        vector<vector<char>> save = board;
        ChangePoint(save,i,j);
        if(save.size() != 0) board = save;
    }
};