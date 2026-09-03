class Solution {
public:
    int findComplement(int num) {
        string s="";
        while(num>0)
        {
            string ch= to_string(num&1);
            s+=ch;
            num=num>>1;
        }
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='0') s[i]='1';
            else s[i]='0';
        }
        
        
        long long int ans=0;
        long long int p=1;
        for(int i=0;i<s.length();i++)
        {
            ans+=(s[i]-'0')*p;
            p*=2;
        }
        return ans;
    
    }
};