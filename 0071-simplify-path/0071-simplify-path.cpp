class Solution {
public:
    string simplifyPath(string path) {
        vector<string> temp;
        int i = 1;
        string tempAnswer;
        while(i < path.size()){
            if(path[i] == '/' || i == path.size()-1){
                if(path[i] != '/'){
                    tempAnswer.push_back(path[i]);
                }

                if(tempAnswer.size() != 0){
                    if(tempAnswer == ".."){
                        if(temp.size() != 0){
                            temp.pop_back();
                        }
                    }
                    else if(tempAnswer != "."){
                        temp.push_back(tempAnswer);
                    }
                    tempAnswer = "";
                }
            }
            else{
                tempAnswer.push_back(path[i]);
            }
            i++;
        }

        if(temp.size() == 0){
            return "/";
        }

        tempAnswer = "";
        for(int k = 0;k < temp.size();k++){
            tempAnswer += ("/" + temp[k]);
        }
        return tempAnswer;
    }
};