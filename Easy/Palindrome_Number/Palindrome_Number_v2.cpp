class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        long long int rev_num=0;
        long long int temp=x;
        while(temp>0){
            int digit=temp%10;
            temp/=10;
            rev_num=rev_num*10+digit;
        }
        return rev_num==(long long int)x;
    }
};