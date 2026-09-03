class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int>fact(n);
        fact[0]=1;
        for(int i=1;i<n;i++){
            fact[i]=fact[i-1]*i;
        }
        vector<char>digits;
        for(int i=1;i<=n;i++){
            digits.push_back('0'+i);
        }
        k--;
        string ans;
        while(n>0){
            int index=k/fact[n-1];
            ans+=digits[index];
            digits.erase(digits.begin()+index);
            k%=fact[n-1];
            n--;
        }
        return ans;
    }
};