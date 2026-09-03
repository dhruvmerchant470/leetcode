class Solution {
public:
    vector<vector<int>>ans;
    void recurse(int index,int target,vector<int>&candidates,vector<int>tmp){
        if(target==0){
            ans.push_back(tmp);
            return;
        }
        for(int i=index;i<candidates.size();i++){
            if(i>index && candidates[i-1]==candidates[i]) continue;
            if(candidates[i]>target) break;
            tmp.push_back(candidates[i]);
            recurse(i+1,target-candidates[i],candidates,tmp);
            tmp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        recurse(0,target,candidates,{});
        return ans;
    }
};