class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>dq;
        vector<int>ans;
        int n=nums.size();
        for(int i=0;i<n;i++){
            while(!dq.empty() && dq.back()<nums[i]) dq.pop_back();
            dq.push_back(nums[i]);
            if(i>=k && nums[i-k]==dq.front()) dq.pop_front();
            if(i>=k-1) ans.push_back(dq.front());
        }
        return ans;
    }
};