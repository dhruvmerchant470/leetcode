class Solution {
public:
    unordered_map<int,unordered_map<int,bool>>dp;
    bool solve(set<int>& stones, int curr, int jumplen, int t){
        if(jumplen<=0){
            return false;
        }
        if(curr>t){
            return false;
        }
        if(curr==t){
            return true;
        }
        if(stones.find(curr)==stones.end()){
            return false;
        }
        if(dp.find(curr)!=dp.end() && dp[curr].find(jumplen)!=dp[curr].end()) return dp[curr][jumplen];
        return dp[curr][jumplen] = 
        solve(stones,curr+jumplen-1,jumplen-1,t) ||
        solve(stones,curr+jumplen+1,jumplen+1,t) ||
        solve(stones,curr+jumplen,jumplen,t);
    }
    bool canCross(vector<int>& stones) {
        set<int>s(stones.begin(),stones.end());
        
        return solve(s,1,1,stones[stones.size()-1]);
    }
};