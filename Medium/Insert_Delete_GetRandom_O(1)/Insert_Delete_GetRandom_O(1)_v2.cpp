class RandomizedSet {
public:
    vector<int>s;
    unordered_map<int, int> mp;
    RandomizedSet() {}
    bool insert(int val) {
        if (mp.find(val) == mp.end()) {
            s.push_back(val);
            mp[val]=s.size()-1;
            return true;
        } else {
            return false;
        }
    }

    bool remove(int val) {
        if (mp.find(val) != mp.end()) {
            s[mp[val]]=s[s.size()-1];
            s.pop_back();
            mp[s[mp[val]]]=mp[val];
            mp.erase(mp.find(val));
            return true;
        } else
            return false;
    }

    int getRandom() {
        return s[rand()%s.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */