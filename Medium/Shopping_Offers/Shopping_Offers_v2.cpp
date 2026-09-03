class Solution {
public:
    int ans = INT_MAX;
    void solve(vector<vector<int>>&special, int index, vector<int>&needs, vector<int>&price, int sum){
        if(index == special.size()){
            for(int i=0;i<needs.size();i++){
                sum+=(needs[i]*price[i]);
            }
            ans = min(ans,sum);
            return;
        }
        int n = special[index].size();
        
        bool flag = true;
        for(int i=0;i<n-1;i++){
            if(special[index][i]>needs[i]){
                flag = false;
                break;
            }
        }
        solve(special,index+1,needs,price,sum);
        if(flag){
            for(int i=0;i<n-1;i++){
                needs[i]-=special[index][i];
            }
            solve(special,index,needs,price,sum+special[index][n-1]);
            for(int i=0;i<n-1;i++){
                needs[i]+=special[index][i];
            }
        }
    }
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        solve(special,0,needs,price,0);
        return ans;
    }
};