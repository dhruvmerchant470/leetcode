class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mp;
        for(auto str: strs){
            vector<int>tmp(26,0);
            for(auto ch: str){
                tmp[ch-'a']++;
            }
            string key;
            for(auto it: tmp){
                key+=to_string(it+'a');
            }
            mp[key].push_back(str);
        }
        vector<vector<string>>res;
        for(auto it: mp){
            res.push_back(it.second);
        }
        return res;
    }
};