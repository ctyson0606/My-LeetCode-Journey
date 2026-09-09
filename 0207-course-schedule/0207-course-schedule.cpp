class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = prerequisites.size();

        unordered_map<int,vector<int>> record;
        unordered_set<int> visited;
        
        vector<int> runCourse;
        for(int i = 0;i < n;i++){
            record[prerequisites[i][0]].push_back(prerequisites[i][1]);
            runCourse.push_back(prerequisites[i][0]);
        }

        n = runCourse.size();
        for(int i = 0; i < n;i++){
            unordered_set<int> onPath;
            if(!check(record, runCourse[i], visited, onPath)) return false;
        }

        return true;
    }

    bool check(unordered_map<int,vector<int>>& record, int finding, unordered_set<int>& visited, unordered_set<int>& onPath){
        if(record.find(finding) == record.end()){
            visited.insert(finding);
            return true;
        }

        if(onPath.find(finding) != onPath.end()) return false;
        onPath.insert(finding);

        if(visited.find(finding) != visited.end()){
            onPath.erase(finding);
            return true;
        } 
        visited.insert(finding);

        vector<int> x = record[finding];
        int n = x.size();

        for(int i = 0;i < n;i++){
            if(!check(record, x[i], visited, onPath)) return false;
        }

        onPath.erase(finding);
        return true;
    }
};