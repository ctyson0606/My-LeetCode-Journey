class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int gasSum = 0;
        for(int i = 0;i<gas.size();i++){
            gasSum += gas[i];
            gasSum -= cost[i];
        }
        if(gasSum < 0){
            return -1;
        }
        bool check = true;
        gasSum = 0;
        int location = 0;
        int checking = 0;
        while(true){
            if(!check){
                check = true;
                gasSum = 0;
                checking = location;
            }
            gasSum += gas[location];
            gasSum -= cost[location];
            if(gasSum < 0){
                check = false;
            }
            location = (location+1) % gas.size();
            if(location == checking && check){
                return checking;
            }
        }
    }
};