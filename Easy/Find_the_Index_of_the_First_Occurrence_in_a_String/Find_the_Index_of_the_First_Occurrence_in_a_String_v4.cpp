#define MOD 998244353
class Solution {
public:
    bool check(string a,string b,long long i){
        long long index=0;
        while(index<a.size()){
            if(a[index]!=b[i]) return  false;
            index++;
            i++;
        }
        return true;
    }
    long long powe(long long n,long long m){
        long long num=1;
        for(long long i=0;i<m;i++){
            num = (num * n)%MOD;
        }
        return num%MOD;
    }
    int strStr(string haystack, string needle) {
        if(needle.size()>haystack.size()) return -1;
        if(needle.size()==haystack.size()) return needle==haystack?0:-1;
        long long n=needle.size();
        long long req_hash=0;
        long long power=powe(26,n-1);
        for(long long i=0;i<n;i++){
            req_hash = ((req_hash*26)%MOD + (needle[i]-'a'))%MOD;
        }
        cout<<req_hash%MOD<<endl;
        long long curr_hash=0;
        for(long long i=0;i<n;i++){
            curr_hash = ((curr_hash*26)%MOD +(haystack[i]-'a'))%MOD;
        }
        if(curr_hash==req_hash){
                cout<<"hi1"<<endl;
                if(check(needle,haystack,0)) return 0;
        }
        
        for(long long i=n;i<haystack.size();i++){
            cout<<curr_hash<<endl;
            curr_hash = (((curr_hash%MOD - (haystack[i-n]-'a')%MOD*power%MOD)*26)%MOD+(haystack[i]-'a')+MOD)%MOD;
            // cout<<curr_hash<<endl;
            if(curr_hash==req_hash){
                cout<<"hi2"<<endl;
                if(check(needle,haystack,i-n+1)) return i-n+1;
            }
        }
        return -1;
    }
};