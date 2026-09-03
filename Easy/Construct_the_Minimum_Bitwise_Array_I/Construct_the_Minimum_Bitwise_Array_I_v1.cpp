class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
    int n=nums.size();
    vector<int>ans(n);
    for(int i=0;i<n;i++){
        ans[i]=-1;
        for(int j=1;j<nums[i];j++){
            int n1=j|j+1;
            if(n1==nums[i]) {
                ans[i]=j;
                break;
            }
        }
    }  
    return ans;
}
};