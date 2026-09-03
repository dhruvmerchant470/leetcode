class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        queue<pair<int,int>>q;
        q.push({sr,sc});
        // visited[sr][sc]=true;
        int s_color = image[sr][sc];
        while(!q.empty()){
            auto t = q.front();
            q.pop();
            int x = t.first;
            int y = t.second;
            visited[x][y]=true;
            image[x][y] = color;

            //down
            if(x+1<n && !visited[x+1][y] && image[x+1][y]==s_color) q.push({x+1,y});
            //up
            if(x-1>=0 && !visited[x-1][y] && image[x-1][y]==s_color) q.push({x-1,y});
            //right
            if(y+1<m && !visited[x][y+1] && image[x][y+1]==s_color) q.push({x,y+1});
            //left
            if(y-1>=0 && !visited[x][y-1] && image[x][y-1]==s_color) q.push({x,y-1});

        }
        return image;
    }
};