class RandomizedSet {
public:
    unordered_set<int> s;
    unordered_map<int, int> mp;
    RandomizedSet() {}
    bool insert(int val) {
        if (mp.find(val) == mp.end()) {
            s.insert(val);
            mp[val]++;
            return true;
        } else {
            return false;
        }
    }

    bool remove(int val) {
        if (mp.find(val)!=mp.end()) {
            mp[val]--;
            if (mp[val] == 0)
                mp.erase(val);
            s.erase(val);
            return true;
        } else
            return false;
    }

    int getRandom() {
        int i = rand() % mp.size();
        auto it=mp.begin();
        advance(it,i);
        return (*it).first;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */