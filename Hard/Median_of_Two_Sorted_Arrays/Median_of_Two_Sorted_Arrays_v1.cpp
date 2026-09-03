class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i=0,j=0;
        vector<int>ans;
        int n=nums1.size(),m=nums2.size();
        while(i<n&&j<m){
            if(nums1[i]>nums2[j]) ans.push_back(nums2[j++]);
            else ans.push_back(nums1[i++]);
        }
        while(i<n) ans.push_back(nums1[i++]);
        while(j<m) ans.push_back(nums2[j++]);
        if(ans.size()&1) return ans[ans.size()/2]*1.0;
        else return (ans[ans.size()/2]+ans[ans.size()/2-1])/2.0;
    }
};