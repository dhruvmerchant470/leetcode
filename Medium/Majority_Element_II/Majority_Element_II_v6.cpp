class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int el1 = INT_MIN,cnt1 = 0;
        int el2 = INT_MIN,cnt2 = 0;
        for(auto &it: nums){
            if(cnt1==0 && it!=el2){
                cnt1=1;
                el1=it;
            }
            else if(cnt2==0 && it!=el1){
                cnt2=1;
                el2=it;
            }
            else if(it==el1) cnt1++;
            else if(it==el2) cnt2++;
            else{
                cnt1--;
                cnt2--;
            }
        }
        cnt1=0;
        cnt2=0;
        int mini = (int)nums.size()/3;
        for(auto &it: nums){
            if(el1==it) cnt1++;
            else if(el2==it) cnt2++;
        }
        vector<int>ans;
        if(cnt1>mini) ans.push_back(el1);
        if(cnt2>mini) ans.push_back(el2);
        return ans;
    }
};