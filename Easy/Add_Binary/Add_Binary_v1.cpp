class Solution {
public:
    string addBinary(string a, string b) {
        string ans="";
        int n=a.size(),m=b.size();
        int i=n-1,j=m-1;
        int carry=0;
        while(i>=0 && j>=0){
            int dig_a=a[i--]-'0',dig_b=b[j--]-'0';
            int sum=dig_a+dig_b+carry;
            char digit=sum%2+'0';
            carry=sum/2;
            ans.push_back(digit);

        }
        while(i>=0){
            int dig_a=a[i--]-'0';
            int sum=dig_a+carry;
            char digit=sum%2+'0';
            carry=sum/2;
            ans.push_back(digit);

        }
        while(j>=0){
            int dig_a=b[j--]-'0';
            int sum=dig_a+carry;
            char digit=sum%2+'0';
            carry=sum/2;
            ans.push_back(digit);
        }
        while(carry>0){
            int sum=carry;
            char digit=sum%2+'0';
            carry=sum/2;
            ans.push_back(digit);

        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};