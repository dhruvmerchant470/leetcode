class Solution {
public:
    int trap(vector<int>& height) {
        int prevMax=INT_MIN;
        int nextMax=INT_MIN;
        int n=height.size();
        vector<int>prev(n);
        vector<int>next(n);
        for(int i=0;i<n;i++){
            prevMax=max(prevMax,height[i]);
            prev[i]=prevMax;
        }
        for(int i=n-1;i>=0;i--){
            nextMax=max(nextMax,height[i]);
            next[i]=nextMax;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=min(prev[i],next[i])-height[i];
        }
        return ans;
    }
};