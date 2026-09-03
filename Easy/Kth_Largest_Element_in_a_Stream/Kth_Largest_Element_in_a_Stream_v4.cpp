class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>>pq;
    int K;
    KthLargest(int k, vector<int>& nums) {
        K=k;
        for(int i=0;i<nums.size();i++){
            if(i<k) pq.push(nums[i]);
            else{
                int top = pq.top();
                if(nums[i]>pq.top()){
                    pq.pop();
                    pq.push(nums[i]);
                }
            }
        }
    }
    
    int add(int val) {
        if(pq.size()>=K){
            int top = pq.top();
            if(val>pq.top()){
                pq.pop();
                pq.push(val);
            }
        }
        else pq.push(val);
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */