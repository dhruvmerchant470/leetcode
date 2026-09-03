class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        queue<pair<int,int>>q;
 
        q.push({sr,sc});
        int y_lim=image.size();
        int x_lim=image[0].size();
        
        vector<vector<int>>visited(y_lim,vector<int>(x_lim,0));
        
        while(!q.empty()){
            pair<int,int>front=q.front();
            q.pop();
            int x1=front.first,y1=front.second;
            visited[x1][y1]=1;
    
            int c1= image[x1][y1];
           
            
            if(y1+1<x_lim&&!visited[x1][y1+1]&&image[x1][y1+1]==c1){
         
                q.push({x1,y1+1});}
            if(y1-1>=0&&!visited[x1][y1-1]&&image[x1][y1-1]==c1) {q.push({x1,y1-1});
           }

            
            if(x1+1<y_lim&&!visited[x1+1][y1]&&image[x1+1][y1]==c1){
                 q.push({x1+1,y1});
               }
            if(x1-1>=0&&!visited[x1-1][y1]&&image[x1-1][y1]==c1) {
                q.push({x1-1,y1});
           }
            image[x1][y1]=color;
        }
        return image;
    }
};