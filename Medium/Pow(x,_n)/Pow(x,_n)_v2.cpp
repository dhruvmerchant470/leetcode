class Solution {
public:
    double helper(double x, int n){
        if(n==0) return 1;
        if(n==1) return x;
        double tmp = helper(x*x,n/2);
        if(n&1) tmp*=x;
        return tmp;
    }
    double myPow(double x, int n) {
       if(n>0) return helper(x,n);
       else return helper(1.0/x,n);
    }   
};