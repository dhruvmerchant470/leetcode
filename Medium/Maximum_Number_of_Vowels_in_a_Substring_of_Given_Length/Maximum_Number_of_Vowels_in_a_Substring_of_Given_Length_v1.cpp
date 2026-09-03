class Solution {
public:
    int maxVowels(string s, int k) {
        map<char,int>mp;
        int maxi = INT_MIN;
        for(int i=0;i<s.size();i++){
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'){
                mp[s[i]]+=1;
            }
            if(i>=k){
                if(mp.find(s[i-k])!=mp.end()) {
                    mp[s[i-k]]-=1;
                    if(mp[s[i-k]]==0) {
                        mp.erase(s[i-k]);
                    }
                }
            }
            if(i>=k-1){
                int sum = 0;
                for(auto it: mp) sum+=it.second;
                maxi = max(maxi,sum);
            }
            
        }
        return maxi;
    }
};