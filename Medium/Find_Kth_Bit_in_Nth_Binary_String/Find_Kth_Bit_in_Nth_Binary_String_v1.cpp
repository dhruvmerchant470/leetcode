class Solution {
public:
    string invert(string s){
        for(int i=0;i<s.size();i++) {
            if(s[i]=='0') s[i]='1';
            else s[i]='0';
        }
        return s;
    }
    string recurse(string s,int n){
        if(n==1) return s;
        // cout<<s<<" "<<n<<endl;
        string tmp = invert(s);
        reverse(tmp.begin(),tmp.end());
        return recurse(s+"1"+tmp,n-1);
    }
    char findKthBit(int n, int k) {
        string ans = recurse("0",n);
        // cout<<ans<<endl;
        return ans[k-1];
    }
};