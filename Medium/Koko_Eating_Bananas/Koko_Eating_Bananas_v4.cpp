class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=0;
        int high=INT_MAX;
        while(low<=high){
            int mid=low+(high-low)/2;
            double time_taken=0;
            for(int i=0;i<piles.size();i++){
                time_taken+=ceil(piles[i]/(mid*1.0));
            }
            if(time_taken>h) low=mid+1;
            else high=mid-1;
        }
        return low;
    }
};