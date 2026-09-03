#define MOD 1000000007
#define ll long long
class Solution {
public:
    vector<int>nextMin(vector<int>&arr){
        stack<int>s;
        vector<int>ans(arr.size(),-1);
        s.push(-1);
        for(int i=arr.size()-1;i>=0;i--){
            int curr=arr[i];
            while(s.top()!=-1 && arr[s.top()]>curr){
                s.pop();
            }
            ans[i]=s.top();
            s.push(i);
        }
        return ans;
    }
    vector<int>prevMin(vector<int>&arr){
        stack<int>s;
        vector<int>ans(arr.size(),-1);
        s.push(-1);
        for(int i=0;i<arr.size();i++){
            int curr=arr[i];
            while(s.top()!=-1 && arr[s.top()]>=curr){
                s.pop();
            }
            ans[i]=s.top();
            s.push(i);
        }
        return ans;
    }
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        vector<int>next(n);
        next=nextMin(arr);
        vector<int>prev(n);
        prev=prevMin(arr);
        ll ans=0;
        for(int i=0;i<arr.size();i++){
            ll left=prev[i]%MOD;
            ll right=next[i]%MOD;
            if(right==-1) right=n;
            ans=(ans%MOD+((i-left)%MOD * ((right-i)%MOD * arr[i]%MOD)%MOD)%MOD)%MOD;
        }
        return ans;
    }
};