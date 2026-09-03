class Solution {
public:
    int mySqrt(int x) {
        long long int s=0,e=x,mid=s+(e-s)/2,ans=-1;
    while(s<=e)
    {
        long long square=mid*mid;
        if(square==x) return mid;
        if (square< x) {
          ans = mid;
          s = mid + 1;
        }
        else{
            e=mid-1;
        }
        mid=s+(e-s)/2;
    }
    return ans ;
    }
};