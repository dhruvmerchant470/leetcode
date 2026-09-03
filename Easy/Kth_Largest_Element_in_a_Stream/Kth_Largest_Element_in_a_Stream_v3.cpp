class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>>pq;
    int elem;
    KthLargest(int k, vector<int>& nums) {
        elem=k;
        int i;
        for(i=0;i<nums.size();i++){
            pq.push(nums[i]);
            // cout<<"hi: "<<nums[i]<<endl;
            if(i==k-1) break;
        }
        i++;
        for(;i<nums.size();i++){
            if(nums[i]>pq.top()){
                // cout<<"hi1: "<<nums[i]<<endl;
                pq.pop();
                pq.push(nums[i]);
            }
        }
    }
    
    int add(int val) {
        if(pq.size()<elem){
            pq.push(val);
        }
        else{
            if(val>pq.top()){
                pq.pop();
                pq.push(val);
            }
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */