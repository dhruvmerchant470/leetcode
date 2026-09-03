class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>>ans(n,vector<int>(n,0));
        for(auto arr: queries){
            for(int i=arr[0];i<=arr[2];i++){
                ans[i][arr[1]]++;
                if(1+arr[3]!=n) ans[i][1+arr[3]]--;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=1;j<n;j++){
                ans[i][j]+=ans[i][j-1];
            }
        }
        return ans;
    }
};