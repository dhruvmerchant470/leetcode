class Solution {
public:
    int minimumOperationsToMakeEqual(int x, int y) {
       queue<pair<int,int>>q;
       q.push({x,0});
       set<int>s;
       while(!q.empty()){
            auto curr = q.front();
            q.pop();
            if(s.find(curr.first)!=s.end()) continue;
            s.insert(curr.first);
            if(curr.first==y) return curr.second;
            if(curr.first%11==0 && curr.first>y) q.push({curr.first/11,curr.second+1});
            if(curr.first%5==0 && curr.first>y) q.push({curr.first/5,curr.second+1});
            if(curr.first-1>=0 && curr.first>y) q.push({curr.first-1,curr.second+1});
            q.push({curr.first+1,curr.second+1});
       } 
       return -1;
    }
};