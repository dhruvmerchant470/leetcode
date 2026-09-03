class Solution {
public:
    #define MOD 1000000007
    long long solve(long long x, long long y){
        if(y == 0) return 1;
        if(y == 1) return x;
        long long t = solve(x , y/2);
        t  = (t%MOD*t%MOD)%MOD;
        if(y&1) t = (t%MOD*x%MOD)%MOD;
        return t;
    }
    int sumDecoded(vector<long long>& nums) {
        long long ans = 0;
        for(auto it: nums){
            long long w = it % 10;
            long long d = it / 10;
            string t = to_string(d);
            string x1 = "";
            string y1 = "";
            for(int i =0 ;i< t.size() ;i++){
                if(i<w) x1+=t[i];
                else y1+=t[i];
            }
            long long x = stol(x1);
            long long y = stol(y1);
            ans = (ans%MOD + solve(x,y)%MOD)%MOD;
        }
        return ans;
    }
};