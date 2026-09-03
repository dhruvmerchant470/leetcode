class Solution {
public:
    string removeDigit(string number, char digit) {
        vector<string>ans;
        for(int i=0;i<number.size();i++){
            if(i!=number.size()-1 && number[i]==digit){
                string s1=number.substr(0,i)+number.substr(i+1,number.size()-i-1);
                ans.push_back(s1);
            }
            else if(i==number.size()-1 && number[i]==digit){
                string s1=number.substr(0,i);
                ans.push_back(s1);
            }
        }
        sort(ans.rbegin(),ans.rend());
        return ans[0];
    }
};