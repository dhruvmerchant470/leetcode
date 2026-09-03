class Solution {
public:
    bool cmp(vector<int>prev,vector<int>curr){
        if(curr[0]<=prev[0]&&curr[1]<=prev[1]&&curr[2]<=prev[2]) return true;
        else return false;
    }
    int maxHeight(vector<vector<int>>& cuboids) {
       for(auto &a :cuboids)
       {
        sort(a.begin(),a.end());

       }
       sort(cuboids.begin(),cuboids.end());
       int n=cuboids.size();
       vector<int>curr(n+1,0);
       vector<int>next(n+1,0);
       for(int curri=n-1;curri>=0;curri--)
       {
        for(int previ=curri-1;previ>=-1;previ--)
        {
            int include=0;
            if(previ==-1||cmp(cuboids[curri],cuboids[previ]))
            {
                include=cuboids[curri][2]+next[curri+1];
            }
            int exclude=next[previ+1];
            curr[previ+1]=max(include,exclude);
        }
        next=curr;
       }
       return curr[0];
    }
};