class Solution {
public:
    long long sumAndMultiply(int n) {
        long long x=0;
        long long sum=0;
        string tmp="";
        while(n>0){
            int digit = n%10;
            if(digit!=0) tmp = to_string(digit) + tmp;
            sum+=digit;
            n/=10;
        }
        if(sum==0) return 0;
        x = stol(tmp);
        return 1LL*x*sum;
    }
};