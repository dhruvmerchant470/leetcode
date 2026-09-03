class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>>pq;
    int K;
    KthLargest(int k, vector<int>& nums) {
        K=k;
        if(nums.size()>0)
        {for(int i=0;i<k&&i<nums.size();i++) pq.push(nums[i]);
        for(int i=k;k<nums.size()&&i<nums.size();i++) {
            int top=pq.top();
            if(top<nums[i]){
                pq.pop();
                pq.push(nums[i]);
            }
        }}
    }
    
    int add(int val) {
        if(!pq.empty()&&pq.size()>=K)
        {
        int top=pq.top();
        if(top<val){
            pq.pop();
            pq.push(val);
        }
        }
        else
        {
            pq.push(val);
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */