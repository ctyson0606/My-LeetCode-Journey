class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> answer;
        int front = 0;
        int back = 0;
        int i = 0;
        bool end = false;
        bool push = false;
        if(intervals.size() == 0){
            answer.push_back(newInterval);
            return answer;
        }

        while(i < intervals.size()){
            if(push){
                answer.push_back(intervals[i]);
                i++;
            }
            if(!end && !push){
                if(intervals[i][1] < newInterval[0]){
                    answer.push_back(intervals[i]);
                    if(i == intervals.size()-1){
                        answer.push_back(newInterval);
                        return answer;
                    }
                }
                else{
                    if(intervals[i][0] >= newInterval[0]){
                        back = newInterval[0];
                    }
                    else{
                        back = intervals[i][0];
                    }
                    end = true;
                    if(intervals[i][0] > newInterval[1]){
                        front = newInterval[1];
                        answer.push_back({back,front});
                        push = true;
                        i--;
                    }
                    else if(intervals[i][1] >= newInterval[1]){
                        front = intervals[i][1];
                        answer.push_back({back,front});
                        push = true;
                    }
            
                    if(i == intervals.size()-1 && !push){
                        front = newInterval[1];
                        answer.push_back({back,front});
                        push = true;
                    }

                    if(i == intervals.size()-1 && front < intervals[i][0]){
                        answer.push_back(intervals[i]);
                    }
                    
                }
                i++;
            }
            else if(!push){
                if(intervals[i][1] > newInterval[1]){
                    if(intervals[i][0] > newInterval[1]){
                        front = newInterval[1];
                        i--;
                    }
                    else{
                        front = intervals[i][1];
                    }
                    answer.push_back({back,front});
                    push = true;
                }
                else if(i == intervals.size()-1){
                    front = newInterval[1];
                    answer.push_back({back,front});
                    push = true;
                }
                i++;
            }
        }

        return answer;
    }
};