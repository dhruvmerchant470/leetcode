class Solution {
public:
    int gcd(int a,int b){
        if(b==0) return a;
        return gcd(b,a%b);
    }
    int gcdOfOddEvenSums(int n) {
        int sum_odd = n*n;
        int sum_even = n*(n+1);
        return gcd(sum_odd,sum_even);
    }
};