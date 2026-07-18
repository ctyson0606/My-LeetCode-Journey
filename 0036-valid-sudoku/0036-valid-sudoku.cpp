class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<char,int> check;
        for(int i = 0; i < 9; i++){
            {
            unordered_map<char,int> check;
            check[1000] = 0;
            for(int j = 0; j < 9;j++){
                if(check.find(board[i][j]) != check.end() && board[i][j] != '.'){
                    return false;
                }
                check[board[i][j]] = 1;
            }
            }
        }

        for(int i = 0; i < 9; i++){
            {
            unordered_map<char,int> check;
            check[1000] = 0;
            for(int j = 0; j < 9;j++){
                if(check.find(board[j][i]) != check.end() && board[j][i] != '.'){
                    return false;
                }
                check[board[j][i]] = 1;
            }
            }
        }

        for(int i = 0; i < 9; i+=3){
            for(int j = 0; j < 9;j+=3){
                unordered_map<char,int> check;
                for(int h = i; h < i+3;h++){
                    for(int k = j ; k < j+3 ; k++){
                        if(check.find(board[h][k]) != check.end() && board[h][k] != '.'){
                            return false;
                        }
                        check[board[h][k]] = 1;
                    }
                }
            }
        }
        return true;
    }

};