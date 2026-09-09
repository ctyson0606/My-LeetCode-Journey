class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> record(numCourses);
        vector<bool> onPath(numCourses,false);
        vector<bool> visited(numCourses,false);
        vector<int> finalAnswer;

        int n = prerequisites.size();
        for(int i = 0; i < n; i++){
            auto& x = prerequisites[i];
            record[x[0]].push_back(x[1]);
        }

        for(int i = 0;i < numCourses; i++){
            if(!check(record, onPath, visited, i, finalAnswer)) return vector<int>(0);
        }

        return finalAnswer;
    }

    bool check(vector<vector<int>>& record, vector<bool>& onPath, vector<bool>& visited, int finding, vector<int>& finalAnswer){
        if(onPath[finding]){
            return false;
        }

        if(visited[finding]){
            return true;
        }

        onPath[finding] = true;
        visited[finding] = true;

        auto& x = record[finding];
        for(int i = 0; i < x.size(); i++){
            if(!check(record,onPath,visited,x[i],finalAnswer)){
                return false;
            }
        }

        onPath[finding] = false;
        finalAnswer.push_back(finding);

        return true;
    }
};