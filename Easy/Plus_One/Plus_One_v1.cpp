class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry=0;
        int n=digits.size();
        for(int i=n-1;i>=0;i--){
            int tmp=digits[i]+carry;
            if(i==n-1) tmp+=1;
            // cout<<tmp<<endl;
            // cout<<carry<<endl;
            int digit=tmp%10;
            carry=tmp/10;
            digits[i]=digit;
        }
        if(carry>0) digits.insert(digits.begin(),carry);
        return digits;
    }
};