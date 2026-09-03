class Solution {
public:
    int myAtoi(string s) {
        bool flag = false;
        bool neg = false;
        // int cnt = 0;
        long long num = 0;
        for(auto it: s){
            if(!flag && it==' ') continue;
            else if(!flag && it=='-') {
                neg = true;
                flag = true;
            }
            else if(!flag && it=='+'){
                flag=true;
            }
            else if((it<'0' || it>'9')) break;
            else{
                // cout<<it<<" ";
                flag=true;
                if(num==0){
                    if(it=='0') continue;
                    else{
                        num = 1LL*num*10+(it-'0');
                    }
                }else{
                    num = 1LL*num*10+(it-'0');
                }
            }
            if(neg && -num<=INT_MIN){
                return INT_MIN;
            }else if(num>INT_MAX){
                return INT_MAX;
            }
        }

        return neg?-num:num;
    }
};