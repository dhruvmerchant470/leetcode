class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1=0;
        int cnt2=0;
        int elt1=INT_MIN;
        int elt2=INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(cnt1==0 && nums[i]!=elt2){
                elt1=nums[i];
                cnt1=1;
            }
            else if(cnt2==0 && nums[i]!=elt1){
                elt2=nums[i];
                cnt2=1;
            }
            else if(nums[i]==elt1) cnt1++;
            else if(nums[i]==elt2) cnt2++;
            else {
                cnt1--;
                cnt2--;
            }
        }
    
        cnt1=0,cnt2=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==elt1) cnt1++;
            if(nums[i]==elt2) cnt2++;
        }
        vector<int>ans;
        if(cnt1>nums.size()/3) ans.push_back(elt1);
        if(cnt2>nums.size()/3) ans.push_back(elt2);
        return ans;
    }
};