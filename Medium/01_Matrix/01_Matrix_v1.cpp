class Solution {
public:
    vector<int>dir={1,0,-1,0,1};
    
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0) q.push({i,j});
                else mat[i][j]=-1;
            }
        }
        while(!q.empty()){
            auto front=q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int new_x=front.first+dir[i];
                int new_y=front.second+dir[i+1];
                if(new_x<0 || new_y<0 || new_x>=mat.size() || new_y>=mat[0].size() || mat[new_x][new_y]!=-1) continue;
                mat[new_x][new_y]=mat[front.first][front.second]+1;
                q.push({new_x,new_y});
            }
        }
        return mat;
    }
};