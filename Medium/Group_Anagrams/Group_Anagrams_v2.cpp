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
        
        string curr=new_str[0].first;
        vector<string>tmp;
        int i=0;
        while(i<N){
            while(i<N && curr==new_str[i].first){
                tmp.push_back(new_str[i].second);
                i++;
            }
            ans.push_back(tmp);
            tmp.clear();
            if(i<N) curr=new_str[i].first;
        }
        
        return ans;
    }
};