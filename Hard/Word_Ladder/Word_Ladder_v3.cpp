class Solution {
public:
    bool diff(string a,string b){
        int cnt=0;
        for(int i=0;i<a.size();i++){
            if(a[i]!=b[i]) cnt+=1;
            if(cnt>1) return false;
        }
        return true;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();
        vector<vector<int>>adj(n+1);
        bool flag = false;
        int index = -1;
        for(int i=0;i<n;i++){
            if(wordList[i]==endWord) {
                flag=true;
                index = i;
            }
            for(int j=i+1;j<n;j++){
                if(diff(wordList[i],wordList[j])){
                    adj[i+1].push_back(j+1);
                    adj[j+1].push_back(i+1);
                }
            }
        }
        if(!flag) return 0;
        for(int i=0;i<n;i++){
            if(diff(beginWord,wordList[i])){
                adj[0].push_back(i+1);
                adj[i+1].push_back(0);
            }
        }
        queue<pair<int,int>>q;
        q.push({0,1});
        vector<bool>visited(n+1,false);
        visited[0]=true;
        while(!q.empty()){
            auto top = q.front();
            q.pop();
            if(top.first==index+1) return top.second;
            for(auto nbr: adj[top.first]){
                if(!visited[nbr]){
                    visited[nbr]=true;
                    q.push({nbr,top.second+1});
                }
            }
        }
        return 0;
    }
};