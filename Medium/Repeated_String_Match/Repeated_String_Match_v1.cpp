#define BASE 26
#define MOD 1000000007
class Solution {
public:
    long long expon(long long N){
        if(N==0) return 1;
        if(N==1) return BASE;

        long long t=expon(N/2);
        t=((t%MOD)*(t%MOD))%MOD;
        if(N&1) return (BASE%MOD)*t;
        else return t;
    }
    bool check(string a,string b, long long index){
        long long i=0;
        while(i<a.size()){
            if(a[i]!=b[index]) return false;
            i++;
            index++;
        }
        return true;
    }
    bool Rabin_karp(string a, string b){
        //to show if b is a substring of a or not
        // cout<<a<<endl;
        // cout<<b<<endl;
        long long m = b.size();
        long long power=expon(m-1);
        long long req_code=0;
        long long curr_code=0;
        for(long long i=0;i<m;i++){
            req_code =( (req_code*BASE+MOD)%MOD + (b[i]-'a'))%MOD;
            curr_code =((curr_code*BASE+MOD)%MOD + (a[i]-'a') )%MOD;
        }
        // cout<<"req: " <<req_code<<endl;
        if(req_code==curr_code && check(b,a,0)) return true;
        for(long long i=m;i<a.size();i++){
            // cout<<curr_code<<endl;
            curr_code = ((curr_code%MOD - (a[i-m]-'a')*power%MOD+MOD)*BASE)%MOD + (a[i]-'a');
            if(req_code==curr_code && check(b,a,i-m+1)) {
                cout<<"hi"<<endl;
                return true;
            }
        }
        return false;
    }
    int repeatedStringMatch(string a, string b) {
        if(a==b) return 1;
        string source=a;
        long long count=1;
        while(source.size()<b.size()){
            count++;
            source+=a;
        }
        
        if(source==b) return count;
        if(Rabin_karp(source,b)) return count;
        
        if(Rabin_karp(source+a,b)) return count+1;
        return -1;
    }
};