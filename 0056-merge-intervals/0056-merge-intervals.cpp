class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int end = intervals[0][0];
        int front = intervals[0][1];
        vector<vector<int>> answer;
        int i = 1;
        if(intervals.size() == 1){
            return intervals;
        }

        while(i < intervals.size()){
            if(intervals[i][0] > front){
                answer.push_back({end,front});
                end = intervals[i][0];
                front = intervals[i][1];
            }
            else{
                if(intervals[i][1] > front){
                    front = intervals[i][1];
                }
            }
            if(i == intervals.size()-1){
                if(intervals[i][1] > front){
                    front = intervals[i][1];
                }
                answer.push_back({end,front});
            }
            i++;
        }

        return answer;
    }
};