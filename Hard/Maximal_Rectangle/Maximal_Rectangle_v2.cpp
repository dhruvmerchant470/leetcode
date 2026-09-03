class Solution {
public:
    vector<int> prevMin(vector<int>& arr){
        int n = arr.size();
        vector<int>prev(n);
        stack<int>s;
        s.push(-1);
        for(int i=0;i<n;i++){
            while(s.top()!=-1 && arr[s.top()]>=arr[i]) s.pop();
            prev[i] = s.top();
            s.push(i);
        }
        return prev;
    }
    vector<int> nextMin(vector<int>& arr){
        int n = arr.size();
        vector<int>next(n);
        stack<int>s;
        s.push(-1);
        for(int i=n-1;i>=0;i--){
            while(s.top()!=-1 && arr[s.top()]>=arr[i]) s.pop();
            next[i] = s.top();
            s.push(i);
        }
        return next;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>>mat(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0) mat[i][j] = matrix[i][j]-'0';
                else {
                    if(matrix[i][j]=='1') mat[i][j] = mat[i-1][j] + 1;
                    else mat[i][j]=0; 
                }
            }
        }
        
        int maxi  = INT_MIN;
        for(int i=0;i<n;i++){
            vector<int>prev = prevMin(mat[i]);
            vector<int>next = nextMin(mat[i]);
            for(int j=0;j<next.size();j++){
                int h = mat[i][j];
                int r = next[j]==-1?next.size():next[j];
                int l = prev[j];
                maxi = max(maxi,(r-l-1)*h);
            }
        }
        return maxi;
    }
};