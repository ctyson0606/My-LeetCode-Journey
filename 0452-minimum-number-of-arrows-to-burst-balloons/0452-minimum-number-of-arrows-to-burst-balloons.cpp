class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        vector<vector<int>> temp;
        bool check;
        int count = 0;
        if(points.size() == 0) return 0;
        if(points.size() == 1) return 1;

        for(int i = 0;i < points.size();i++){
            if(i == 0){
                if(points[i][1] < points[i+1][0]){
                    count++;
                }
                else{
                    temp.push_back(points[i]);
                }
            }
            else if(i == points.size()-1){
                if(points[i][0] > points[i-1][1]){
                    count++;
                }
                else{
                    temp.push_back(points[i]);
                }
            }
            else{
                if(points[i][0] > points[i-1][1] && points[i][1] < points[i+1][0]){
                    count++;
                }
                else{
                    temp.push_back(points[i]);
                }
            }

        }
        
        if(temp.size() == 0) return count;
        if(temp.size() == 1) return ++count;

        int front = temp[0][1];
        int back = temp[0][0];
        for(int i = 1;i < temp.size();i++){
            bool checkBack = false;
            bool checkFront = false;
            if(back <= temp[i][0] && front >= temp[i][0]){
                back = temp[i][0];
                checkBack = true;
            }
            
            if(front >= temp[i][1]){
                front = temp[i][1];
                checkFront = true;
            }

            if(!checkFront && !checkBack){
                count++;
                back = temp[i][0];
                front = temp[i][1];
            }

            if(i == temp.size()-1) count++;
        }

        return count;

    }
};