class Solution {
public:
    vector<int> nextSmaller(vector<int>heights,int n)
    {
        stack<int>s;
        s.push(-1);
        vector<int>nxt(n);
        for(int i=n-1;i>=0;i--)
        {
             while(s.top()!=-1 &&heights[s.top()]>=heights[i])
             {
                s.pop();
             }
             int ans1=s.top();
                nxt[i]=ans1;
                s.push(i);
        }
        return nxt;
    }
    vector<int> prevSmaller(vector<int>heights,int n)
    {
        stack<int>s;
        s.push(-1);
        vector<int>nxt(n);
        for(int i=0;i<n;i++)
        {
             while(s.top()!=-1 &&heights[s.top()]>=heights[i])
             {
                s.pop();
             }
             int ans1=s.top();
                nxt[i]=ans1;
                s.push(i);
        }
        return nxt;
    }
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int>prev(n);
        vector<int>next(n);
        prev=prevSmaller(heights,n);
        next=nextSmaller(heights,n);
        int area=INT_MIN;
        for(int i=0;i<n;i++)
        {
            int l=heights[i];
            if(next[i]==-1) next[i]=n;
            int b=next[i]-prev[i]-1;
            int narea=l*b;
            area=max(narea,area);
        }
        return area;

    }
};