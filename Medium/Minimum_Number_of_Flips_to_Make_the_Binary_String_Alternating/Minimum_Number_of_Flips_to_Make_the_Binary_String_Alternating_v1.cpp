class Solution {
public:
    int zero_even=0;
    int one_even=0;
    int one_odd=0;
    int zero_odd=0;
    int helper(string s, int index,int size){
        for(int i=index;i<index+size;i++){
            if(i&1){
                if(s[i]=='0') zero_odd++;
                else one_odd++;
            }
            else{
                if(s[i]=='0') zero_even++;
                else one_even++;
            }
        }
        // cout<<zero_even<<endl;
        // cout<<one_odd<<endl;
        // cout<<one_even<<endl;
        // cout<<zero_odd<<endl;
        return size-max(one_even+zero_odd,one_odd+zero_even);
    }

    int minFlips(string s) {
        int size=s.size();
        int ans=helper(s,0,size);
        for(int i=0;i<size;i++){
            if(size&1){
                if(s[i]=='1'){
                    //1 ab even position pe hi ayega
                    int one_odd_tmp =0;
                    if(one_even>0) one_odd_tmp = one_even - 1;
                    int one_even_tmp = one_odd + 1;
                    int zero_even_tmp = zero_odd;
                    int zero_odd_tmp = zero_even;
                    zero_even = zero_even_tmp;
                    zero_odd = zero_odd_tmp;
                    one_odd  = one_odd_tmp;
                    one_even = one_even_tmp;
                    int tmp = size-max(zero_even+one_odd,zero_odd+one_even);
                    ans=min(ans,tmp);
                }
                else{
                    int zero_odd_tmp =0;
                    if(zero_even>0) zero_odd_tmp = zero_even - 1;
                    int zero_even_tmp = zero_odd + 1;
                    int one_even_tmp = one_odd;
                    int one_odd_tmp = one_even;
                    one_even = one_even_tmp;
                    one_odd = one_odd_tmp;
                    zero_odd  = zero_odd_tmp;
                    zero_even = zero_even_tmp;
                    int tmp = size-max(zero_even+one_odd,zero_odd+one_even);
                    ans=min(ans,tmp);
                }
                cout<<ans<<endl;
            }
        }
        return ans;
    }
};