class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int curr = 0;
        int mini = INT_MAX;
        bool flag = false;
        for(int i=0;i<nums.size();i++){
            curr += nums[i];
            if(curr>=x){
                flag = true;
            }
            if(curr==x) {
                mini = min(mini,i+1);
                break;
            }
        }
        if(!flag) return -1;
        cout<<"1 "<<mini<<endl;
        curr = 0;
        for(int i=nums.size()-1;i>=0;i--){
            curr += nums[i];
            
            if(curr==x) {
                mini = min(mini,(int)nums.size()-i);
                break;
            }
        }
        cout<<"2 "<<mini<<endl;

        int n = nums.size();
        int m = 2*n;
        vector<int>arr(2*nums.size());
        for(int i=0;i<arr.size();i++){
            arr[i] = nums[i%nums.size()];
        }
        curr = 0;
        int l = 0;
        int r = n;
        for(int i=0;i<n;i++) curr+=arr[i];
        while(r<m){
            if(l>n) break;
            curr+=arr[r];
            while(curr>x && r>l && l<n){
                curr-=arr[l];
                l+=1;
            }
            if(curr==x){
                mini = min(mini,r-l+1);
            }
            r+=1;
        }
        cout<<"3 "<<mini<<endl;

        return mini == INT_MAX ? -1: mini;
    }
};