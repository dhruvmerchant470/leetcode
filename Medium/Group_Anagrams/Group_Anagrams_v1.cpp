class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int N=strs.size();
        vector<pair<string,string>>new_str;
        for(int i=0;i<N;i++){
            string tmp=strs[i];
            sort(tmp.begin(),tmp.end());
            new_str.push_back({tmp,strs[i]});
        }
        sort(new_str.begin(),new_str.end());
        vector<vector<string>>ans;
        // for(auto it: new_str) cout<<it.first<<" "<<it.second<<endl;
        string curr=new_str[0].first;
        vector<string>tmp;
        int i=0;
        while(i<N){
            if(curr==new_str[i].first){
                tmp.push_back(new_str[i].second);
                i++;
            }
            else{
                ans.push_back(tmp);
                curr=new_str[i].first;
                tmp.clear();
            }
        }
        if(tmp.size()!=0) ans.push_back(tmp);
        return ans;
    }
};