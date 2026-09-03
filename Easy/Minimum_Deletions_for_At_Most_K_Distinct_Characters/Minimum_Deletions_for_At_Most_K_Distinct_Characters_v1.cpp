class Solution {
public:
    int minDeletion(string s, int k) {
        map<char, int> mp;
        for (int i = 0; i < s.size(); i++) {
            if (mp.find(s[i]) == mp.end())
                mp[s[i]] = 1;
            else
                mp[s[i]] += 1;
        }
        std::vector<std::pair<char, int>> vec(mp.begin(),
                                                     mp.end());

        // Sort the vector by values
        std::sort(vec.begin(), vec.end(), [](const auto& a, const auto& b) {
            return a.second < b.second; // ascending order
        });
        int cnt = 0;
        int num = mp.size() - k;
        for(int i=0;i<num;i++) cnt+=vec[i].second;
        return cnt;
    }
};