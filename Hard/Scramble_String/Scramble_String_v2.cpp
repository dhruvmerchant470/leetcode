class Solution {
public:
    struct pair_hash {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const {
        auto hash1 = hash<T1>{}(p.first);  // Hash for the first element
        auto hash2 = hash<T2>{}(p.second); // Hash for the second element
        return hash1 ^ (hash2 << 1);       // Combine the two hashes
    }
    };
    bool helper(string s1, string s2, unordered_map<pair<string,string>,bool, pair_hash>&dp){
        if(s1==s2) return true;
        if(s1.length()<=1) return false;
        if(dp.find({s1,s2})!=dp.end()) return dp[{s1,s2}];
        bool flag=false;
        int n=s1.length();
        for(int i=1;i<n;i++){
            if(
                (helper(s1.substr(0,i),s2.substr(n-i,i),dp) && helper(s1.substr(i,n-i),s2.substr(0,n-i),dp))
                || 
                (helper(s1.substr(0,i),s2.substr(0,i),dp) && helper(s1.substr(i,n-i),s2.substr(i,n-i),dp)) 
            ){
                flag=true;
                break;
            }
        }
        return dp[{s1,s2}]=flag;
    }
    bool isScramble(string s1, string s2) {
        unordered_map<pair<string,string>,bool,pair_hash>dp;
        return helper(s1,s2,dp);
    }
};