#pragma GCC optimize("Ofast,inline,unroll-loops")
class Fancy {
public:
    #define MOD 1000000007
    long long modinv(long long x){
        long long res = 1, p = MOD-2;
        while(p){
            if(p&1) res = res*x % MOD;
            x = x*x % MOD;
            p >>= 1;
        }
        return res;
    }
    long long mult;
    long long add;
    vector<long long>vals;
    Fancy() {
        add=0;
        mult=1;
    }
    
    void append(int val) {
        long long x = (val-add+MOD)%MOD;
        x = x*modinv(mult)%MOD;
        vals.push_back(x);
    }
    
    void addAll(int inc) {
        add = (add+inc)%MOD;
    }
    
    void multAll(int m) {
        mult = (m*mult)%MOD;
        add = (add*m)%MOD;
    }
    
    int getIndex(int idx) {
        return idx<vals.size()?(vals[idx]*mult+add)%MOD:-1;
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */