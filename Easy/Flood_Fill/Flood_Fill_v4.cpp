class Solution {
public:
    bool check(int x, int y, vector<vector<bool>>&visited, vector<vector<int>>& image, int org_color){
        int n=image[0].size();
        int m=image.size();
        if(x>=0 && y>=0 && x<m && y<n && image[x][y]==org_color && visited[x][y]==false)      return true;
        else return false;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<int>dir={1,0,-1,0,1};
        int org_color=image[sr][sc];
        queue<pair<int,int>>q;
        vector<vector<bool>>visited(image.size(),vector<bool>(image[0].size(),false));
        q.push({sr,sc});
        while(!q.empty()){
            auto top=q.front();
            visited[top.first][top.second]=1;
            q.pop();
            for(int i=0;i<dir.size()-1;i++){
                int new_x=top.first+dir[i];
                int new_y=top.second+dir[i+1];
                if(check(new_x,new_y,visited,image,org_color)){
                    q.push({new_x,new_y});
                }
            }
            image[top.first][top.second]=color;
        }
        return image;
    }
};