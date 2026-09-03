class Solution {
public:
    #define MOD 1000000007
    #define MAX 100001
    int pow[MAX];
    void cal(){
        pow[0]=1;
        for(int i=1;i<MAX;i++){
            pow[i]=pow[i-1]*10LL%MOD;
        }
    }
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        cal();
        int n = s.length();
        vector<int>len(n+1,0);
        vector<int>sum(n+1,0);
        vector<int>mul(n+1,0);
        for(int i=0;i<n;i++){
            int digit = s[i]-'0';
            sum[i+1]=sum[i]+digit;
            if(digit){
                mul[i+1] = (mul[i]*10LL + digit)%MOD;
                len[i+1]=len[i]+1;
            }else{
                mul[i+1]=mul[i];
                len[i+1]=len[i];
            }
        }

        vector<int>ans;
        for(auto &it: queries){
            long long sub = mul[it[0]]*1LL*(pow[len[it[1]+1]-len[it[0]]])%MOD;
            long long x = (mul[it[1]+1]-sub+MOD)%MOD;
            ans.push_back(x*(sum[it[1]+1]-sum[it[0]])%MOD);
        }
        return ans;

    }
};