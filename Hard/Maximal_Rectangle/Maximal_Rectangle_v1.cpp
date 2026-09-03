class Solution {
public:
    vector<int>next(vector<int>&tmp){
        stack<int>s;
        s.push(tmp.size());
        vector<int>ans(tmp.size());
        for(int i=tmp.size()-1;i>=0;i--){
            while(s.top()!=tmp.size() && tmp[s.top()]>=tmp[i]) s.pop();
            ans[i]=s.top();
            s.push(i);
        }
        return ans;
    }
    vector<int>prev(vector<int>&tmp){
        stack<int>s;
        s.push(-1);
        vector<int>ans(tmp.size());
        for(int i=0;i<tmp.size();i++){
            while(s.top()!=-1 && tmp[s.top()]>=tmp[i]) s.pop();
            ans[i]=s.top();
            s.push(i);
        }
        return ans;
    }
    int help(vector<int>&tmp){
        vector<int>nxt=next(tmp),pre=prev(tmp);
        long long max_are=INT_MIN;
        for(int i=0;i<tmp.size();i++){
            max_are=max(max_are,1LL*(nxt[i]-pre[i]-1)*tmp[i]);
        }
        return max_are;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        vector<vector<int>>mat(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                mat[i][j]=(matrix[i][j]=='1');
            }
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==1){
                    mat[i][j]+=mat[i-1][j];
                }
            }
        }
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            ans=max(ans,help(mat[i]));
        }
        return ans;
    }
};