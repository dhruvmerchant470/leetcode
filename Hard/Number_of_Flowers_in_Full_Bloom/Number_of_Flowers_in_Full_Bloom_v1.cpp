class Solution {
public:
    static bool cmp(pair<long long,long long>&a,pair<long long,long long>&b){
        if(a.first==b.first) return a.second>b.second;
        return a.first<b.first;
    }
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        vector<pair<long long,long long>>all_flowers;
        for(long long i=0;i<flowers.size();i++){
            all_flowers.push_back({flowers[i][0],1});
            all_flowers.push_back({flowers[i][1]+1,-1});
        }
        for(int i=0;i<people.size();i++){
            all_flowers.push_back({people[i],-2});
        }
        sort(all_flowers.begin(),all_flowers.end(),cmp);
        // for(auto it :all_flowers){
        //     cout<<it.first<<" "<<it.second<<endl;
        // }
        map<long long,long long>flowers_time;
        long long cnt=0;
        long long size=all_flowers.size();
        long long max_time=all_flowers[size-1].first;
        long long index=0;
        for(int i=0;i<size;i++){
            if(all_flowers[i].second!=-2){
                cnt+=all_flowers[i].second;
            }
            else{
                flowers_time[all_flowers[i].first]=cnt;
            }
        }
        vector<int>ans;
        for(auto t: people){
            ans.push_back(flowers_time[t]);
        }
        return ans;
    }
};