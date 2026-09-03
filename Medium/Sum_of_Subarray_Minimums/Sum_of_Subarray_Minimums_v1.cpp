#define MOD 1000000007
class Solution {
public:
    vector<int> nxtmin(vector<int>&arr){
        stack<int>s;
        s.push(-1);
        int  n=arr.size();
        vector<int>nxt(n,-1);
        for(int i=n-1;i>=0;i--)
        {
            while(s.top()!=-1&&arr[s.top()]>arr[i]){
                s.pop();
            }
            int ans=s.top();
            nxt[i]=ans;
            s.push(i);
        }
        return nxt;
    }
    vector<int> prevmin(vector<int>&arr){
        stack<int>s;
        s.push(-1);
        int n=arr.size();
        vector<int>nxt(n,-1);
        for(int i=0;i<n;i++)
        {
            while(s.top()!=-1&& arr[s.top()]>=arr[i]){
                s.pop();
            }
            int ans=s.top();
            nxt[i]=ans;
            s.push(i);
        }
        return nxt;
    }
    int sumSubarrayMins(vector<int>& arr) {
        vector<int>nxt,prev;
        nxt=nxtmin(arr);
        prev=prevmin(arr);
       long long int ans=0;
        int n=arr.size();
        
        for(int i=0;i<n;i++){
          long long int left=prev[i]%MOD;
          long long int right=nxt[i]%MOD;
          if(right==-1) right=n%MOD;
          
          ans=ans%MOD +( (i-left)%MOD * ((right-i)%MOD * (arr[i]%MOD))%MOD )%MOD;
        }
        return ans;
    }
};