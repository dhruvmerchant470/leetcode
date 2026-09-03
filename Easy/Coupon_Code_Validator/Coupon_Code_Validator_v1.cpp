class Solution {
private:
vector<string>elec,groc,pharma,res;
public:
    bool check(string s){
        if(s.size()==0) return false;
        for(int i=0;i<s.size();i++){
            if(!isalnum(s[i]) && !(s[i]=='_')) return false;
        }
        return true;
    }
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        for(int i=0;i<code.size();i++){
            if(!isActive[i]) continue;
            if(!check(code[i])) continue;
            // cout<<code[i]<<endl;
            if(businessLine[i]=="electronics") elec.push_back(code[i]);
            else if(businessLine[i]=="grocery") groc.push_back(code[i]);
            else if(businessLine[i]=="pharmacy") pharma.push_back(code[i]);
            else if(businessLine[i]=="restaurant")  res.push_back(code[i]);
        }
        sort(elec.begin(),elec.end());
        sort(groc.begin(),groc.end());
        sort(res.begin(),res.end());
        sort(pharma.begin(),pharma.end());
        vector<string>ans;
        for(auto it: elec) ans.push_back(it);
        for(auto it: groc) ans.push_back(it);
        for(auto it: pharma) ans.push_back(it);
        for(auto it: res) ans.push_back(it);
        return ans;
    }
};