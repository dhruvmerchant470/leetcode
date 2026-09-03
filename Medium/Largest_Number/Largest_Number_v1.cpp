class Solution {
public:
    static bool cmp(string &a,string &b){
        string tmp1=a+b;
        string tmp2=b+a;
        if(tmp1>tmp2) return true;
        else return false;
    }
    string largestNumber(vector<int>& nums) {
        vector<string>res;
        for(int i=0;i<nums.size();i++){
            res.push_back(to_string(nums[i]));
        }
        sort(res.begin(),res.end(),cmp);
        string ans="";
        for(auto it: res){
            ans+=it;
        }
        int index=0;
        while(index<ans.size() && ans[index]=='0') index++;
        return index==ans.size()?"0":ans.substr(index,ans.size()-index);
    }
};