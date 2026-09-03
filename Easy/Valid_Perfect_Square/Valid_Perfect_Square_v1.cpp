class Solution {
public:
    bool isPerfectSquare(int num) {
    long long int s=0,e=num-1,mid=s+(e-s)/2,ans=-1;
    while(s<=e)
    {
        long long square=mid*mid;
        if(square==num) return true;
        if (square< num) {
          ans = mid;
          s = mid + 1;
        }
        else{
            e=mid-1;
        }
        mid=s+(e-s)/2;
    }
    if(num==1) return true;
    return false ;
    
    }
};