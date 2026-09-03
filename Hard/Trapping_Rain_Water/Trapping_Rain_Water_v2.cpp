class Solution {
public:
    int trap(vector<int>& height) {
        int prevmax=INT_MIN;
        int nextmax=INT_MIN;
        int n = height.size();
        vector<int>prev(n);
        vector<int>next(n);
        for(int i=0;i<n;i++){
            prevmax=max(prevmax,height[i]);
            nextmax=max(nextmax,height[n-i-1]);
            prev[i]=prevmax;
            next[n-i-1]=nextmax;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=(min(prev[i],next[i])-height[i]);
        }
        return ans;    
    }
};