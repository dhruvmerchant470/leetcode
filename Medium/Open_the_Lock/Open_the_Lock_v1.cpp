class Solution {
public:

    int openLock(vector<string>& deadends, string target) {
        queue<pair<int,string>>q1;
        vector<bool>visited(10000,0);
        q1.push({0,"0000"});
        for(auto &s: deadends) {
            visited[stoi(s)]=1;
        }
        if(visited[0]==1) return -1;
        while(!q1.empty()){
            pair<int,string> front=q1.front();
            visited[stoi(front.second)]=true;
            q1.pop();
            //8 Ways
            if(front.second==target) return front.first;
            for(int i=0;i<4;i++){
                for(int j=-1;j<=1;j+=2){
                    string new_string=front.second;
                    char &to_move=new_string[i];
                    to_move=(to_move-'0'+j+10)%10+'0';
                    if(!visited[stoi(new_string)]){
                        q1.push({front.first+1,new_string});
                        visited[stoi(new_string)]=1;
                    }
                    
                }
            }
        }
        return -1;   
    }
};