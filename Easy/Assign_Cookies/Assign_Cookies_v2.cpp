class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(s.begin(),s.end());
        sort(g.begin(),g.end());
        int cnt=0;
        int i=0,j=0;
        while(i<s.size()&&j<g.size()){
            if(s[i]>=g[j]){
                i++;
                j++;
                cnt++;
            }
            else{
                i++;
            }
        }
        return cnt;
    }
};