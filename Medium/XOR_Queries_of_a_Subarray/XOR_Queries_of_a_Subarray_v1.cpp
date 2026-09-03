class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int>ans(queries.size());
        vector<int>prefix(arr.size());
        prefix[0]=arr[0];
        for(int i=1;i<arr.size();i++){
            prefix[i]=prefix[i-1]^arr[i];
        }
        for(int i=0;i<queries.size();i++){
            if(queries[i][0]==0) ans[i]=prefix[queries[i][1]];
            else ans[i]=prefix[queries[i][1]]^prefix[queries[i][0]-1];
        }
        return ans;
    }
};