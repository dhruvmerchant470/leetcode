class Solution {
public:
    char a[3]={'C','G','T'};
    char b[3]={'A','G','T'};
    char c[3]={'A','C','T'};
    char d[3]={'A','G','C'};
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        queue<pair<string,int>>q;
        set<string>s_bank(bank.begin(),bank.end());
        map<string,bool>visited;
        visited[startGene]=1;
        q.push({startGene,0});
        while(!q.empty()){
            auto top=q.front();
            if(top.first==endGene) return top.second;
            string tmp=top.first;
            int level=top.second;
            q.pop();
            for(int i=0;i<8;i++){
                if(tmp[i]=='A'){
                    string tmp1=tmp;
                    for(int j=0;j<3;j++){
                        tmp1[i]=a[j];
                        if(visited.find(tmp1)==visited.end() && s_bank.find(tmp1)!=s_bank.end()) {
                            q.push({tmp1,level+1});
                            visited[tmp1]=1;
                        }
                    }
                }
                else if(tmp[i]=='C'){
                    string tmp1=tmp;
                    for(int j=0;j<3;j++){
                        tmp1[i]=b[j];
                        if(visited.find(tmp1)==visited.end() && s_bank.find(tmp1)!=s_bank.end()) {
                            q.push({tmp1,level+1});
                            visited[tmp1]=1;
                        }

                    }
                }
                else if(tmp[i]=='G'){
                    string tmp1=tmp;
                    for(int j=0;j<3;j++){
                        tmp1[i]=c[j];
                        if(visited.find(tmp1)==visited.end() && s_bank.find(tmp1)!=s_bank.end()) {
                            q.push({tmp1,level+1});
                            visited[tmp1]=1;
                        }

                    }
                }else{
                    string tmp1=tmp;
                    for(int j=0;j<3;j++){
                        tmp1[i]=d[j];
                    if(visited.find(tmp1)==visited.end() && s_bank.find(tmp1)!=s_bank.end()) {
                            q.push({tmp1,level+1});
                            visited[tmp1]=1;
                        }
                    }
                }
            }
        }
        return -1;
    }
};