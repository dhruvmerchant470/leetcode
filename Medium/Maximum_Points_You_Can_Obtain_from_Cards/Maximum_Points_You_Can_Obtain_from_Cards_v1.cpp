class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int m = 2*n;
        vector<int>new_arr(m);
        for(int i=0;i<m;i++){
            new_arr[i]=cardPoints[i%n];
        }
        int maxi = INT_MIN;
        int curr = 0;
        for(int i=n-k;i<n+k;i++){
            if(i>=(n-k)+k) curr-=new_arr[i-k];
            curr+=new_arr[i];
            if(i>=(n-k)+k-1) maxi = max(maxi,curr);
        }
        return maxi;
    }
};