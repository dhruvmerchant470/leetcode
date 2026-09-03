class Solution {
public:
    int nthUglyNumber(int n) {
        unordered_map<long long ,long long >mp;
        priority_queue<long long ,vector<long long>,greater<long long>>pq;
        if(n==1) return 1;
        for(int i=0;i<n;i++){
            if(pq.empty()){
            pq.push(1);
            mp[1]=true;
            continue;
            }
            long long  num=pq.top();
            pq.pop();
            mp[num]=false;
            if(!mp[num*2]){
                pq.push(num*2);
                mp[num*2]=true;
            }
            
            if(!mp[num*3]){
                pq.push(num*3);
                mp[num*3]=true;
            }
            
            if(!mp[num*5]){
                pq.push(num*5);
                mp[num*5]=true;
            }
        }
        return pq.top();
    }
};