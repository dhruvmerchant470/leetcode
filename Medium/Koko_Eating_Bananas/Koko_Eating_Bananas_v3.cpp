class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int  maxi=INT_MIN;
        int s=0,e=INT_MAX;
       
        
        while(s<=e){
            double ans=0;
            int mid=s+(e-s)/2;
            for(int i=0;i<piles.size();i++){
                ans+=ceil(piles[i]/(mid*1.0));
            }
            if(ans>h) s=mid+1;
            else e=mid-1;
        }
        return s;
    }
};