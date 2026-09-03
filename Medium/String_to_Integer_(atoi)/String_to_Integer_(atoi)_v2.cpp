class Solution {
public:
    int myAtoi(string s) {
        int index = 0;
        while (s[index] == ' ')
            index++;
        int sign = 1;
        if (s[index] == '-') {
            sign = -1;
            index++;
        } else if (s[index] == '+') {
            index++;
        }
        long long int result=0;
        while(s[index]>='0' && s[index]<='9'){
            result=1LL*result*10+s[index]-'0';
            index++;
            if(sign*result>INT_MAX-1) return INT_MAX;
            else if(sign * result < -INT_MAX-1) return -INT_MAX-1;

        }

        return sign*result;
    }
};