class Solution {
private:
    unordered_map<int,unordered_set<int>> record;
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for(int i = 0; i < grid.size();i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(grid[i][j] == '1'){
                    if(record.find(i) == record.end() || record[i].find(j) == record[i].end()){
                        count++;
                        AddUsedPoint(grid, i,j);
                    }
                }
            }
        }

        return count;
    }

    void AddUsedPoint(vector<vector<char>>& grid,int i, int j){
        if(grid[i][j] == '1'){
            cout << i << " " << j << "\n";
            record[i].insert(j);
            if(i+1 < grid.size()){
                if(record.find(i+1) == record.end() || record[i+1].find(j) == record[i+1].end()){
                    AddUsedPoint(grid,i+1,j);
                }
            }
            if(j+1 < grid[i].size()){
                if(record.find(i) == record.end() || record[i].find(j+1) == record[i].end()){
                    AddUsedPoint(grid,i,j+1);
                }
            } 
            
            if(i - 1 >= 0){
                if(record.find(i-1) == record.end() || record[i-1].find(j) == record[i-1].end()){
                    AddUsedPoint(grid,i-1,j);
                }
            } 
            if(j - 1 >= 0){
                if(record.find(i) == record.end() || record[i].find(j-1) == record[i].end()){
                    AddUsedPoint(grid,i,j-1);
                }
            } 
        }
    }
};