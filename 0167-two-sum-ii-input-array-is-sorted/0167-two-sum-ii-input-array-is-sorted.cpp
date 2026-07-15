class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> answer;
        int i = 0;
        int j = numbers.size()-1;
        int temp;
        while(true){
            temp = numbers[i] + numbers[j];
            if(temp > target){
                j--;
            }
            else if(temp < target){
                i++;
            }
            else{
                answer.push_back(i+1);
                temp = numbers[j];
                break;
            }
        }
        for(int h = i+1; h < j+1;h++){
            if(numbers[h] == temp){
                answer.push_back(h+1);
            }
        }
        return answer;
    }
};