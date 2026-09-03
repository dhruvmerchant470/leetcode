class Solution {
public:
    vector<int> nextmin(vector<int>&arr){
        int n=arr.size();
        stack<int>s;
        s.push(-1);
        vector<int>ans(n,-1);
        for(int i=n-1;i>=0;i--){
            int curr=arr[i];
            while(s.top()!=-1&&arr[s.top()]>=curr){
                s.pop();
            }
            ans[i]=s.top();
            s.push(i);
        }
        return ans;
    }
    vector<int> prevmin(vector<int>&arr){
        int n=arr.size();
        stack<int>s;
        s.push(-1);
        vector<int>ans(n,-1);
        for(int i=0;i<n;i++){
            int curr=arr[i];
            while(s.top()!=-1&&arr[s.top()]>=curr){
                s.pop();
            }
            ans[i]=s.top();
            s.push(i);
        }
        return ans;
    }
    
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        long long area=0;
        vector<int>next(n);
        next=nextmin(heights);
        vector<int>prev(n);
        prev=prevmin(heights);
        for(int i=0;i<n;i++){
            int left=prev[i];
            int right=next[i];
            if(right==-1) right=n;
            long long newarea=(right-left-1)*heights[i];
            area=max(newarea,area);

        }
    return area;
    }
};