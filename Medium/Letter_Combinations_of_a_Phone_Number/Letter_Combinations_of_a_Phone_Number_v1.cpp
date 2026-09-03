class Solution {
private:
    void solve(string digits,int index,string output,vector<string>&ans,string matching[])
    {
        if(index>=digits.length()) 
        {
            ans.push_back(output);
            return;
        }
        int nbr=digits[index]-'0';
        string match=matching[nbr];
        for(int i=0;i<match.length();i++)
        {
            output.push_back(match[i]);
            solve(digits,index+1,output,ans,matching);
            output.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        string output;
        if(digits.length()==0) return ans;
        string matching[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        solve(digits,0,output,ans,matching);
        return ans;
    }
};