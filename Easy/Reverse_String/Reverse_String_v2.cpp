class Solution {
public:
    void reverseString(vector<char>& s) {
        stack<char>ans;
        int n=s.size();
        for(int i=0;i<n;i++) ans.push(s[i]);
        
        for(int i=0;i<n;i++) 
        {
            s[i]=ans.top();
            ans.pop();
        }
        
    }
};