class Solution {
public:
    vector<vector<string>>res;
    map<string,int>depth;
    void dfs(string word,string beginWord,vector<string>&wordList,vector<string>seq){
        cout<<word<<endl;
        if(word==beginWord){
            reverse(seq.begin(),seq.end());
            res.push_back(seq);
            // reverse(seq.begin(),seq.end());
            // cout<<"h"<<endl;
            return;
        }
        int curr_depth=depth[word];
        for(auto w: wordList){
            if(check(w,word) && depth.count(w) && curr_depth==depth[w]+1){
                seq.push_back(w);
                // cout<<"ji"<<endl;
                dfs(w,beginWord,wordList,seq);
                seq.pop_back();
            }
        }

    }
    bool check(string a,string b){
        if(a.size()!=b.size()) return false;
        int cnt=0;
        for(int i=0;i<a.size();i++){
            if(a[i]!=b[i]) cnt++;
        }
        return cnt==1;
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        queue<string>q;
        depth[beginWord]=0;
        q.push(beginWord);
        map<string,bool>vis;
        vis[beginWord]=1;
        bool flag=1;
        for(auto w: wordList){
            if(w==beginWord){
                flag=0;
                break;
            }
        }
        if(flag) wordList.push_back(beginWord);
        while(!q.empty()){
            auto top=q.front();
            q.pop();
            if(top==endWord){
                break;
            }
            for(int i=0;i<wordList.size();i++){
                if(!vis[wordList[i]] && check(wordList[i],top)){
                    q.push(wordList[i]);
                    vis[wordList[i]]=1;
                    depth[wordList[i]]=depth[top]+1;
                }
            }
        }
        // cout<<depth.count(endWord)<<endl;
        if(depth.count(endWord)){
            // cout<<depth[endWord]<<" ff"<<endl;
            vector<string>seq;
            seq.push_back(endWord);
            // cout<<"hi"<<endl;
            dfs(endWord,beginWord,wordList,seq);
            return res;
        }
        else return {};
    }
};