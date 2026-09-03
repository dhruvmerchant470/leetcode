class Solution {
public:
    int bitwiseComplement(int n) {
        int ans=0;
        int i=0;
        if(n==0){
            return 1;
        }
        else{
        while(n!=0){
            int bit= !(n&1);
            ans=bit*pow(2,i)+ans;
            n=n>>1;
            i++;
        }
        }
        return ans;
    }
};