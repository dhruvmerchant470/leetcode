
class Solution {
public:
    vector<int> prev(vector<int>&heights){
        stack<int>s;
        s.push(-1);
        int n=heights.size();
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            while(s.top()!=-1 && heights[s.top()]>=heights[i]) s.pop();
            ans[i]=s.top();
            s.push(i);
        }
        return ans;
    }   
    vector<int> next(vector<int>&heights){
        stack<int>s;
        s.push(-1);
        int n=heights.size();
        vector<int>ans(n);
        for(int i=n-1;i>=0;i--){
            while(s.top()!=-1 && heights[s.top()]>=heights[i]) s.pop();
            ans[i]=s.top();
            s.push(i);
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int>next1,prev1;
        next1=next(heights);
        prev1=prev(heights);
        int area=INT_MIN;
        int n=heights.size();
        for(int i=0;i<n;i++){
            int h=heights[i];
            int right=next1[i];
            int left=prev1[i];
            if(right==-1) right=n;
            int w=right-left-1;
            int new_area=h*w;
            area=max(area,new_area);
        }
        return area;
    }
};