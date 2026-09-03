class Solution {
public:
    int mySqrt(int x) {
        if(x==1) return 1;
        double l=0,r=x;
        // double x1=x;
        while(l<=r){
            double mid=(l+r)/2.0;
            double sq=mid*mid*1.0;
            // cout<<sq<<endl;
            if(abs(sq-x)<0.00001) return (int)mid;
            else if(sq>x) r=mid;
            else l=mid;
        }
        return -1;
    }
};