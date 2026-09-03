class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> lastIndex(128, -1); // ASCII character set
        int maxLen = 0;
        int start = 0; // start index of current window

        for (int i = 0; i < s.size(); i++) {
            if (lastIndex[s[i]] >= start) {
                // character repeated in current window
                start = lastIndex[s[i]] + 1;
            }
            lastIndex[s[i]] = i; // update last seen index
            maxLen = max(maxLen, i - start + 1);
        }

        return maxLen;
    }
};
