class Solution {
public:
    int m;
    int n;
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int cnt = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '1'){
                    clearIsland(grid, i ,j);
                    cnt++;
                }
            }            
        }

        return cnt;
    }

    void clearIsland(vector<vector<char>>& grid, int i, int j){
        if(i >= m || j >= n || i <= -1 || j <= -1) return;
        if(grid[i][j] != '1') return;

        grid[i][j] = '0';
        clearIsland(grid, i+1, j);
        clearIsland(grid, i-1, j);
        clearIsland(grid, i, j+1);
        clearIsland(grid, i, j-1);
    }
};