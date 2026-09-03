class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1=="0" || num2=="0") return "0";
        string ans;
        int n1 = num1.size();
        int n2 = num2.size();
        for(int i=n2-1;i>=0;i--){
            string tmp = "";
            for(int k=0;k<n2-i-1;k++) tmp.push_back('0');
            int carry = 0;
            for(int j=n1-1;j>=0;j--){
                int a = num2[i]-'0';
                int b = num1[j]-'0';
                int c = a*b + carry;
                carry = c/10;
                int digit = c%10;
                tmp.push_back('0'+digit);
            }
            if(carry>0){
                tmp.push_back('0'+carry);
            }
            // reverse(tmp.begin(),tmp.end());
            // cout<<tmp<<endl;
            string tmp2 = ans;
            ans = tmp;
            tmp = tmp2;
            // cout<<ans<<endl;
            int i1=0,j1=0,carry2=0;
            while(i1<ans.size() && j1<tmp.size()){
                int sum = (ans[i1]-'0')+(tmp[j1]-'0')+carry2;
                int digit = sum%10;
                carry2 = sum/10;
                ans[i1]='0'+digit;
                i1++;
                j1++;
                // cout<<"hi"<<endl;
            }
            while(i1<ans.size()){
                int sum = (ans[i1]-'0')+carry2;
                int digit = sum%10;
                carry2 = sum/10;
                ans[i1]='0'+digit;
                i1++;
                // cout<<"hi2"<<endl;
            }
            // cout<<ans<<endl;
            if(carry2>0){
                ans.push_back('0'+carry2);
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};