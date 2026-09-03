class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int maxi=-1;
        int n=nums.size();
        int cnt=0;
        //all odds
        for(int i=0;i<n;i++){
            if(nums[i]&1){
                cnt++;
            }
            maxi=max(maxi,cnt);
        }
        //all eves
        cnt=0;
        for(int i=0;i<n;i++){
            if(nums[i]%2==0){
                cnt++;
            }
            maxi=max(maxi,cnt);
        }
        //eve odds
        cnt=0;
        bool flag=1;
        for(int i=0;i<n;i++){
            if(flag && nums[i]%2==0){
                cnt++;
                flag=0;
            }
            else if(!flag && nums[i]%2==1){
                cnt++;
                flag=1;
            }
            maxi=max(maxi,cnt);
        }
        //odd eves
        cnt=0;
        flag=1;
        for(int i=0;i<n;i++){
            if(flag && nums[i]%2==1){
                cnt++;
                flag=0;
            }
            else if(!flag && nums[i]%2==0){
                cnt++;
                flag=1;
            }
            maxi=max(maxi,cnt);
        }
        return maxi;
    }
};