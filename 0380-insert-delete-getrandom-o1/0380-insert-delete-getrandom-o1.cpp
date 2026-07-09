class RandomizedSet {
private:
    unordered_map<int,int> List;
    vector<int> OList;
public:
    RandomizedSet() {
    }
    
    bool insert(int val) {
        if(List.find(val) == List.end()){
            OList.push_back(val);
            List[val] = OList.size()-1;
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        if(List.find(val) != List.end()){
            int index = List[val];
            int value = OList[OList.size()-1];
            OList[List[val]] = value;
            List[value] = index;
            List.erase(val);
            OList.erase(OList.end()-1);
            return true;
        }
        return false;
    }
    
    int getRandom() {
        int randomnumber = rand();
        int index = randomnumber % OList.size();
        return OList[index];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */