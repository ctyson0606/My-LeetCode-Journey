class Solution {
public:
    int strStr(string haystack, string needle) {
        vector<int> index;
        for(int i = 0; i < haystack.size(); i++){
            if(needle[0] == haystack[i]){
                index.push_back(i);
            }
        }

        if(index.size() == 0){
            return -1;
        }

        bool check;
        for(int i = 0; i < index.size(); i++){
            check = true;
            for(int j = 0; j < needle.size(); j++){
                if(j + index[i] >= haystack.size()){
                    return -1;
                }
                if(needle[j] != haystack[j + index[i]] && check){
                    check = false;
                }
                if(j == needle.size()-1 && check){
                    return index[i];
                }
            }
        }
        return -1;
    }
};