class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int>ransom(26,0);
        for(auto ch: ransomNote) ransom[ch-'a']++;
        for(auto ch: magazine)  ransom[ch-'a']--;
        for(int i=0;i<26;i++) if(ransom[i]>0) return false;
        return true;
    }
};