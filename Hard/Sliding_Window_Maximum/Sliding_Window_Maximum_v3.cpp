class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>q;
        vector<int>ans;
        int n=nums.size();
        for(int i=0;i<n;i++){
            while(!q.empty() && q.back()<nums[i]) q.pop_back();
            q.push_back(nums[i]);
            if(i>=k && nums[i-k]==q.front()) q.pop_front();
            if(i>=k-1) ans.push_back(q.front());
        }
        return ans;
    }

};