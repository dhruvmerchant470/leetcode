class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char,string>mp;
        int j=0;
        unordered_map<char,bool>visited;
        unordered_map<string,bool>visited1;

        for(int i=0;i<pattern.length();i++){
            if(visited[pattern[i]]){
                
                int length=mp[pattern[i]].length();
                j+=length;
            }

            if(visited[pattern[i]]==false){
            string s1="";
           
            while(j<s.length()&&s[j]!=' ')
            {
                s1+=s[j++];
            }
            cout<<s1<<endl;
            if(visited1[s1]==false)
                mp[pattern[i]]=s1;
            visited1[s1]=true;
            }
            j++;
            visited[pattern[i]]=true;
            
        }
        string new1="";
        for(auto i: mp){
            cout<<i.first<<" "<<i.second<<endl;
        }
        for(int i=0;i<pattern.length();i++)
        {
            new1+=(mp[pattern[i]]+" ");
        }
        new1.pop_back();
        if(new1==s) return true;
        else
        return false;


    }
};