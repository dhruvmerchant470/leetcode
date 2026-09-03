#define vec vector<int>
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vec>res;
        priority_queue<vec,vector<vec>,greater<vec>>pq;
        pq.push({nums1[0]+nums2[0],0,0});
        set<pair<int,int>>visited;
        visited.insert({0,0});
        while(k-- && !pq.empty()){
            auto top=pq.top();pq.pop();
            int i=top[1];
            int j=top[2];
            res.push_back({nums1[i],nums2[j]});
            if(j+1<nums2.size() && visited.find({i,j+1})==visited.end()){
                visited.insert({i,j+1});
                pq.push({nums1[i]+nums2[j+1],i,j+1});
            }
            if(i+1<nums1.size() && visited.find({i+1,j})==visited.end()){
                visited.insert({i+1,j});
                pq.push({nums1[i+1]+nums2[j],i+1,j});
            }
        }
        return res;
    }
};