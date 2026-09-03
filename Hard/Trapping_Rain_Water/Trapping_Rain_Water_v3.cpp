class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int prevmax = INT_MIN;
        int nextmax = INT_MIN;
        vector<int>prev(n);
        vector<int>next(n);
        for(int i=0;i<n;i++){
            prevmax = max(height[i],prevmax);
            nextmax = max(height[n-i-1],nextmax);
            prev[i] = prevmax;
            next[n-i-1] = nextmax;
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            cout<<i<<" "<<prev[i]<<" "<<next[i]<<endl;
            ans += min(prev[i],next[i])-height[i];
        }
        return ans;
    }
};