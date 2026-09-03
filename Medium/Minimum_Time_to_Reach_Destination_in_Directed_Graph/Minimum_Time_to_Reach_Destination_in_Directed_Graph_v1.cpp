class Solution {
public:
    map<int,vector<vector<int>>>adj;
    int minTime(int n, vector<vector<int>>& edges) {
        int E=edges.size();
        for(auto edge: edges){
            adj[edge[0]].push_back({edge[1],edge[2],edge[3]});
        }
        set<pair<int,int>>s;
        vector<int>timer(n,INT_MAX);
        timer[0]=0;
        s.insert({timer[0],0});
        while(!s.empty()){
            auto top=*(s.begin());
            s.erase(s.begin());
            // cout<<top.first<<" "<<top.second<<endl;
            for(auto nbr: adj[top.second]){
                int t=top.first;
                if(t>=nbr[1] && t<=nbr[2] && t+1<timer[nbr[0]]){
                    timer[nbr[0]]=t+1;
                    s.insert({timer[nbr[0]],nbr[0]});
                }
                else if(t<nbr[1] && timer[nbr[0]]>nbr[1]+1){
                    timer[nbr[0]]=nbr[1]+1;
                    s.insert({timer[nbr[0]],nbr[0]});
                }
            }
        }

        return timer[n-1]==INT_MAX?-1:timer[n-1];
    }
};