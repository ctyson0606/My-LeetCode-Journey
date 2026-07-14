class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> answer;
        string temp;
        vector<int> width;
        if(words.size() == 1){
            temp = words[0] + string(maxWidth-words[0].size(),' ');
            answer.push_back(temp);
            return answer;
        }
        for(int i = 0; i < words.size() ; i++){
            width.push_back(words[i].size());
        }

        int widthPerLine = maxWidth;
        int h = 0;
        int line = 0;
        unordered_map<int,int> pairing;
        while(h < width.size()){
            if(widthPerLine == maxWidth){
                widthPerLine -= width[h];
            }
            else{
                widthPerLine -= (width[h]+1);
            }

            if(widthPerLine >= 0){
                pairing[h] = line;
                h++;
            }
            else{
                widthPerLine = maxWidth;
                line++;
            }
        }
        int maxLine = line;

        temp = "";
        line = 0;
        h = 0;
        widthPerLine = maxWidth;
        int size = 0;
        int widthCount;
        int widthRemain;
        while(true){
            if(pairing[h] == line){
                widthPerLine -= width[h];
                size++;
                h++;
            }
            else{
                h = h - size;
                if(line == maxLine){
                    for(int i = 0;i < size;i++){
                        if(i == 0){
                            temp = words[h];
                        }
                        else{
                            temp = temp + " " + words[h];
                        }

                        if(h == words.size()-1){
                            temp = temp + string(maxWidth-temp.size(),' ');
                        }
                        h++;
                    }
                    answer.push_back(temp);
                    break;
                }
                else if(size == widthPerLine+1){
                    for(int i = 0;i < size;i++){
                        if(i == 0){
                            temp = words[h];
                        }
                        else{
                            temp = temp + " " + words[h];
                        }
                        h++;
                    }   
                }
                else{
                    if(size == 1){
                        temp = words[h] + string(maxWidth-words[h].size(),' ');
                        h++;
                    }
                    else{
                    widthCount = widthPerLine % (size-1);
                    widthRemain = widthPerLine / (size-1);
                    for(int i = 0;i < size;i++){
                        if(i == 0){
                            temp = words[h];
                        }
                        else{
                            if(widthCount > 0){
                                temp = temp + string(widthRemain+1,' ') + words[h];
                                widthCount--;
                            }
                            else{
                                temp = temp + string(widthRemain,' ') + words[h];
                            }
                            
                        }
                        h++;
                    }   
                    }
                }
                answer.push_back(temp);
                temp = "";
                widthPerLine = maxWidth;
                line++;
                size = 0;
                }

            }
        return answer;
}
};