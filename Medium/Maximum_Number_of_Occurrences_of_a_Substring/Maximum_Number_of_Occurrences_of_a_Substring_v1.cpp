class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        unordered_map<string, int> mp;
        vector<int> freq(26, 0);

        int distinct = 0;
        int ans = 0;
        int l = 0;

        for (int r = 0; r < s.size(); r++) {

            if (freq[s[r] - 'a'] == 0)
                distinct++;

            freq[s[r] - 'a']++;

            if (r - l + 1 > minSize) {
                freq[s[l] - 'a']--;

                if (freq[s[l] - 'a'] == 0)
                    distinct--;

                l++;
            }

            if (r - l + 1 == minSize && distinct <= maxLetters) {
                string sub = s.substr(l, minSize);
                mp[sub]++;

                ans = max(ans, mp[sub]);
            }
        }

        return ans;
    }
};