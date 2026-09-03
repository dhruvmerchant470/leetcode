class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>s;
        s.push(-1);
        int n=nums2.size();
        unordered_map<int,int>mp;
        for(int i=n-1;i>=0;i--){
            while(s.top()!=-1 && s.top()<nums2[i]) s.pop();
            mp[nums2[i]]=s.top();
            s.push(nums2[i]);
        }
        vector<int>ans;
        for(int i=0;i<nums1.size();i++){
            ans.push_back(mp[nums1[i]]);
        }
        return ans;
    }
};