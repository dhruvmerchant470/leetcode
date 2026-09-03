class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        sort(nums1.begin(),nums1.end());
        bool eood = nums1[0]%2;
        bool odd = eood==1;
        for(int i=1;i<nums1.size();i++){
            if(eood==1){
                //odd
                if(nums1[i]%2==0){
                    if(!odd) return false; 
                }
            }else{
                //even
                if(nums1[i]%2==1){
                    if(!odd) return false;
                }
            }

            if(!odd) odd = nums1[i]%2==1;
        } 
        return true;
    }
};