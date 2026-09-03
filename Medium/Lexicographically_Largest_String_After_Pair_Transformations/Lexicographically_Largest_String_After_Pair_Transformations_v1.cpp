class Solution {
public:
    #define ll long long
    string solve(ll num){
        string ans = "";
        
        ll index = 0;
        
        while(num > 0){
            ll digit = num & 1;
            
            if(index < 25){
                if(digit){
                    ans += ('a' + index);
                }
            }
            else{
                if(digit){   
                ll cnt = 1 << (index - 25);
                for(ll i=0;i<cnt;i++) ans.push_back('z');
                }
            }
            
            index += 1;
            num = num >> 1;
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
    
    vector<string> largestString(vector<int>& nums) {
        vector<string> ans;
        for(auto it: nums){
            ans.push_back(solve(it));
        }
        // cout<<solve(100000000)<<endl;
        return ans;
    }
};