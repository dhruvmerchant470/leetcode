#define MOD 1000000007
class Solution {
public:
    int bs(vector<int>&nums, int index, int target){
        int low=index;
        int high=nums.size()-1;
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]<=target){
                ans=mid;
                low=mid+1;
            }
            else high=mid-1;
        }
        return ans;
    }
    void power(vector<int>&two,int n){
        for(int i=1;i<=n;i++){
            two[i]=(two[i-1]*2)%MOD;
        }
    }
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int>two(n+1);
        two[0]=1;
        power(two,n);
        int ans=0;
        int l=0,r=n-1;
        while(l<=r){
            if(nums[l]+nums[r]<=target){
                ans=(ans+two[r-l])%MOD;
                l++;
            }
            else r--;
        }
        return ans;
    }
};