class Solution {
public:
    double solve(double x,long long int n){
        if(n==0) return 1;
        double tmp=solve(x,n/2);
        tmp*=tmp;
        if(n%2==0) return tmp;
        else return tmp*x; 

    }
    double myPow(double x, int n) {
        if(x==1) return 1;
        if(x==0 && n>0) return 0;
        long long int n1=n;
        if(n<0){
            x=1.0/x;
            n1=-n1;
        } 
        return solve(x,n1);
    }
};