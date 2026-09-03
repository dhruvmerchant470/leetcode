class Solution {
public:
    int mySqrt(int x) {
        int l=0,r=x;
        while(l<=r){
            int mid=(l+r)/2;
            long int sq=1LL*mid*mid;
            if(sq==x) return mid;
            else if(sq>x) r=mid-1;
            else l=mid+1;
        }
        return r;
    }
};