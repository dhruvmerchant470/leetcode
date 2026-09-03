class Solution {
public:
    void solve(vector<int>&candidates,int target,vector<vector<int>>&ans,int index,int sum,vector<int>&temp){
        if(sum==target) {
            ans.push_back(temp);
            return;
        }
        else if(sum>target) return;
        else{
        int n=candidates.size();
        for(int i=index;i<n;i++){
            if(i!=index&&candidates[i]==candidates[i-1]) continue;
            sum+=candidates[i];
            temp.push_back(candidates[i]);
            solve(candidates,target,ans,i+1,sum,temp);
            sum-=candidates[i];
            temp.pop_back();
        }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int>t;
        sort(candidates.begin(),candidates.end());
        solve(candidates,target,ans,0,0,t);
        return ans;
    }
};