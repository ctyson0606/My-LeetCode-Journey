class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> answer;
        unordered_map<string,int> tempNum;
        int index = 0;
        for(int i = 0;i < strs.size();i++){
            string temp = strs[i];
            sort(temp.begin(),temp.end());
            if(tempNum.find(temp) == tempNum.end()){
                tempNum[temp] = index;
                index++;
                answer.push_back({strs[i]});
            }
            else{
                answer[tempNum[temp]].push_back(strs[i]);
            }
        }
        return answer;
    }
};
