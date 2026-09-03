class Solution {
public:
    vector<int> nextMin(vector<int>&heights){
        stack<int>s;
        vector<int>pos(heights.size());
        for(int i=heights.size()-1;i>=0;i--){
            while(!s.empty() && heights[s.top()] >= heights[i]){
                s.pop();
            }
            pos[i]=s.empty()?-1:s.top();
            s.push(i);
        }
        return pos;
    }
    vector<int> prevMin(vector<int>&heights){
        stack<int>s;
        vector<int>pos(heights.size());
        for(int i=0;i<heights.size();i++){
            while(!s.empty() && heights[s.top()] >= heights[i]){
                // cout<<i<<" t "<<heights[i]<<" "<<s.top()<<endl;
                s.pop();
            }
            pos[i]=s.empty()?-1:s.top();
            s.push(i);
        }
        return pos;
    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int>next = nextMin(heights);
        vector<int>prev = prevMin(heights);
        long long ans = 0;
        for(int i=0;i<heights.size();i++){
            // cout<<heights[i]<<" "<<next[i]<<" "<<prev[i]<<endl;
            int l = prev[i];
            int r;
            if(next[i]==-1) r = heights.size();
            else r = next[i];

            ans= max((r-l-1)*heights[i]*1LL,ans);
        }    

        return ans;
    }
};