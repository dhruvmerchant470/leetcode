#define pii pair<int,int>
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<pair<int,pii>,vector<pair<int,pii>>,greater<pair<int,pii>>>pq;
        pq.push({0,{0,0}});
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
        dist[0][0]=0;
        int dir[]={-1,0,1,0,-1};
        while(!pq.empty()){
            auto top=pq.top();
            pq.pop();
            if(top.second.first==n-1 && top.second.second==m-1){
                return top.first;
            }
            for(int i=0;i<4;i++){
                int nx=top.second.first+dir[i];
                int ny=top.second.second+dir[i+1];
                if(nx>=0 && ny>=0 && nx<n && ny<m){
                    int ne=max(top.first,abs(heights[nx][ny]-heights[top.second.first][top.second.second]));
                    if(dist[nx][ny]>ne){
                        dist[nx][ny]=ne;
                        pq.push({ne,{nx,ny}});
                    }
                }
            }
        }
        return 0;
    }
};