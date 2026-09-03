class Solution {
public:
    #define ll long long
    ll power(int n,int index){
        if(index==0) return 1;
        ll tmp = power(n,index/2);
        tmp *=tmp;
        if(index&1) tmp*=n;
        return tmp;
    }
    vector<int> grayCode(int n) {
        ll tmp1 = power(2,n);
        cout<<tmp1<<endl;
        set<int>ans;
        for(int i=0;i<tmp1;i++) ans.insert(i);
        vector<int>ans1;
        ans1.push_back(0);
        ans.erase(0);
        // cout<<ans.size()<<endl;
        int index=0;
        while(!ans.empty()){
            // cout<<index<<" "<<ans1.size()<<endl;
            int prev = ans1[index];
            for(int i=0;i<32;i++){
                int tmp1 = prev^(1<<i);
                if(ans.find(tmp1)!=ans.end()) {
                    ans1.push_back(tmp1);
                    ans.erase(tmp1);
                    break;
                }
            }
            index++;
        }
        // for(int i=0;i<ans1.size();i++) cout<<ans1[i]<<" ";
        // cout<<endl;
        return ans1;
    }
};