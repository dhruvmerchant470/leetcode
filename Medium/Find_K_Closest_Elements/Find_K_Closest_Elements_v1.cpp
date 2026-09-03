class cmp{
    public:
    bool operator()(pair<int,pair<int,bool>>&a,pair<int,pair<int,bool>>&b){
        return (a.second.first>b.second.first)||(a.second.first==b.second.first&&a.first>b.first);
    }
};
class Solution {

public:
    void print(priority_queue<pair<int,pair<int,bool>>,vector<pair<int,pair<int,bool>>>,cmp>pq)
    {
        while(!pq.empty()){
            pair<int,pair<int,bool>>top=pq.top();
            cout<<top.first<<" "<<top.second.first<<" "<<top.second.second<<endl;
            pq.pop();
        }
    }
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        priority_queue<pair<int,pair<int,bool>>,vector<pair<int,pair<int,bool>>>,cmp>pq;
        for(int i=0;i<arr.size();i++){
            pq.push({arr[i],{abs(arr[i]-x),(x>arr[i])}});
        }
        print(pq);
        vector<int>ans;
        int i=0;
        while(i<k){
            pair<int,pair<int,bool>> top=pq.top();
            ans.push_back(x+top.second.first*pow(-1,top.second.second));
            pq.pop();
            i++;
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};