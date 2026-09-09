class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = prerequisites.size();

        vector<vector<int>> record(numCourses);
        vector<bool> visited(numCourses,false);
        vector<bool> onPath(numCourses,false);
        for(int i = 0;i < n;i++){
            record[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        
        for(int i = 0; i < numCourses ;i++){
            if(!check(record, i, visited, onPath)) return false;
        }

        return true;
    }

    bool check(vector<vector<int>>& record, int finding, vector<bool>& visited, vector<bool>& onPath){
        if(onPath[finding]) return false;
        onPath[finding] = true;

        if(visited[finding]){
            onPath[finding] = false;
            return true;
        } 
        visited[finding] = true;

        vector<int>& x = record[finding];
        int n = x.size();

        for(int i = 0;i < n;i++){
            if(!check(record, x[i], visited, onPath)) return false;
        }

        onPath[finding] = false;
        return true;
    }
};