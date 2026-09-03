class Solution {
public:
    vector<int>dir={1,0,-1,0,1};
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        
        int cnt=0;
        for(int i=0;i<grid1.size();i++){
            
            for(int j=0;j<grid1[0].size();j++){
                bool flag=1;
                if(grid2[i][j]==1){
                    fnc(grid1,grid2,i,j,flag);
                    if(flag) cnt++;
                }
            }
        }
        return cnt;
    }

    void fnc(vector<vector<int>>& grid1, vector<vector<int>>& grid2,int x,int y,bool &flag){
        if(x<0||y<0||x>=grid1.size()||y>=grid1[0].size()) return;
        if(grid2[x][y]==0) return;
        if(grid2[x][y]){
            if(grid1[x][y]==0){
                flag=0;
                return;
            }
            grid2[x][y]=0;
        }
        for(int i=0;i<4;i++)
            fnc(grid1,grid2,x+dir[i],y+dir[i+1],flag);
    }
};