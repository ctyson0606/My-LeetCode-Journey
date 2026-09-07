class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n = equations.size();
        unordered_map<string,vector<pair<string,double>>> record;

        for(int i = 0; i < n;i++){
            record[equations[i][0]].push_back(pair(equations[i][1],values[i]));
            record[equations[i][1]].push_back(pair(equations[i][0], 1.0 / values[i]));
        }

        n = queries.size();
        vector<double> answer(n,-1.0);
        for(int i = 0; i < n; i++){
            if(record.find(queries[i][0]) == record.end() || record.find(queries[i][1]) == record.end()){
                answer[i] = -1.0;
            }
            else{
                unordered_set<string> visited;
                answer[i] = GetEdge(record,visited,queries[i][0],queries[i][1],1.0);
            }
        }

        return answer;
        
    }

    double GetEdge(unordered_map<string,vector<pair<string,double>>>& record, unordered_set<string>& visited,const string& start, const string& require, double acc){
        if(start == require) return acc;
        visited.insert(start);

        for(int i = 0; i < record[start].size();i++){
            if(visited.find(record[start][i].first) != visited.end()) continue;

            double tempAnswer = GetEdge(record,visited,record[start][i].first,require,acc*record[start][i].second);
            if(tempAnswer > 0) return tempAnswer;
        }

        return -1.0;
    }
};