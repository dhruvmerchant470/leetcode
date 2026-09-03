#define MOD 1000000007
#define BASE 26
bool check(string a,string b,long long index){
    long long i=0;
    while(i<a.size()){
        if(a[i]!=b[index]) return false;
        index++;
        i++;
    }
    return true;
}
long long expon(long long N){
    if(N==0) return 1;
    if(N==1) return BASE;
    long long t=expon(N/2);
    t=(t*t)%MOD;
    if(N&1) return ((BASE%MOD)*t+MOD)%MOD;
    else return t;
}
class Solution {
public:
    long long strStr(string haystack, string needle) {
        //use rabin karp metthod
        long long n=needle.size();
        long long req_hash=0;
        long long curr_hash=0;
        long long power = expon(n-1);
        for(long long i=0;i<n;i++){
            req_hash = ((req_hash*BASE+MOD)%MOD + (needle[i]-'a'))%MOD;
            curr_hash= ((curr_hash*BASE+MOD)%MOD + (haystack[i]-'a'))%MOD;
        }
        cout<<req_hash<<endl;
        if(req_hash==curr_hash && check(needle,haystack,0)) return 0;

        for(long long i=n;i<haystack.size();i++){
            cout<<curr_hash<<endl;
            curr_hash = ((curr_hash%MOD - (haystack[i-n]-'a')*power%MOD+MOD)*BASE)%MOD + (haystack[i]-'a');
            if(req_hash==curr_hash && check(needle,haystack,i-n+1)) return i-n+1;
        }
        return -1;

    }
};