class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>>ans(n,vector<int>(n,0));
        for(auto arr :queries){
            for(int i=arr[0];i<=arr[2];i++){
                for(int j=arr[1];j<=arr[3];j++){
                    ans[i][j]+=1;
                }
            }
        }
        return ans;
    }
};