
bool customSort(pair<string, int>& a, pair<string, int>& b) {
    // Compare based on string length
    if(a.second>b.second) return true;
    else if(a.second==b.second) return a.first<b.first;
    else return false;
}
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> mp;
        for (auto i : words)
            mp[i] = -1;
        for (auto i : words) {
            if (mp[i] != -1)
                mp[i]++;
            else
                mp[i] = 1;
        }
        vector<pair<string, int>> vec(mp.begin(), mp.end());
        // Sort the vector using the custom comparator
        sort(vec.begin(), vec.end(), customSort);
        vector<string>ans;
        ans.push_back(vec[0].first);
        for (int i = 1; i < k; i++) {
            ans.push_back(vec[i].first);
        }
        
        return ans;
    }
};