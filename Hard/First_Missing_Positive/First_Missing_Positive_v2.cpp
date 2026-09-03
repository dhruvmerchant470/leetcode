class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        map<int,bool>check;
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            check[nums[i]]=0;
            maxi=max(nums[i],maxi);
            if(nums[i]>0){
                check[nums[i]]=1;
            }
        }
        for(int i=1;i<maxi;i++){
            if(check[i]==false) return i;
        }
        if(maxi<0) return 1;
        return maxi+1;
    }
};