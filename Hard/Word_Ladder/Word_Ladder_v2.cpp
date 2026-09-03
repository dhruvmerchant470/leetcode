class Solution {
public:
    bool diff(string a, string b){
        int cnt=0;
        for(int i=0;i<a.size();i++){
            if(a[i]!=b[i]) cnt+=1;
            if(cnt>1) return false;
        }
        return true;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<int>>edges;
        bool flag = true;
        int final_idx = -1;
        for(int i=0;i<wordList.size();i++){
            for(int j=i+1;j<wordList.size();j++){
                if(diff(wordList[i],wordList[j])){
                    edges.push_back({i+1,j+1});
                }
            }
            if(wordList[i]==endWord) {
                flag = false;
                final_idx = i+1;
            }
            if(diff(wordList[i],beginWord)){
                edges.push_back({0,i+1});
            }
        }
        
        if(flag) return 0;
        unordered_map<int,vector<int>>adj;
        for(auto it: edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        int len = 0;
        queue<pair<int,int>>q;
        q.push({0,1});
        unordered_map<int,bool>visited;
        visited[0]=true;
        while(!q.empty()){
            auto top = q.front();
            q.pop();
            if(top.first==final_idx) return top.second;
            for(auto nbr: adj[top.first]){
                if(!visited[nbr]){
                    q.push({nbr,top.second+1});
                    visited[nbr]=true;
                }
            }
        }
        return 0;
    }
};