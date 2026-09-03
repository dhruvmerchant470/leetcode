class Solution {
public:
    vector<vector<int>>res;
    void solve(vector<int>tmp,vector<int>&vec,int index,int k){
        if(tmp.size()==k){
            res.push_back(tmp);
            return;
        }
        if(index>=vec.size()) return;
        for(int i=index;i<vec.size();i++){
            tmp.push_back(vec[i]);
            solve(tmp,vec,i+1,k);
            tmp.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int>vec(n);
        for(int i=0;i<n;i++) vec[i]=i+1;
        solve({},vec,0,k);
        return res;
    }
};