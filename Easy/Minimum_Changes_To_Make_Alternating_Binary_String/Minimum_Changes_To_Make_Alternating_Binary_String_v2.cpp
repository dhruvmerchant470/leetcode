class Solution {
public:
    int minOperations(string s) {
        int n=s.size();
        int cnt=0;
        int cnt1=0;
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            //0101 case
            if(i&1 && s[i]=='0') cnt++;
            else if(i%2==0 && s[i]=='1') cnt++;

            //10101 case
            else if(i%2==0 && s[i]=='0') cnt1++;
            else if(i&1 && s[i]=='1') cnt1++;
        }
        // cout<<cnt<<" "<<cnt1<<endl;
        return min(cnt,cnt1);
    }
};