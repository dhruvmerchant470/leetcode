class Solution {
public:
    int solve(int n){
        int ans=0;
        while(n>0){
            int digit=n%10;
            n/=10;
            ans+=digit*digit;
        }
        return ans;
    }
    bool isHappy(int n) {
        unordered_map<int,bool>mp;
        while(n>1){
            cout<<n<<endl;
            n=solve(n);
            if(mp.count(n)>0) return false;
            mp[n]=1;
        }
        return true;
    }
};