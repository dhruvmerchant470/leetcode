class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>>mp;
        for(int i=0;i<k;i++){
            mp.push(nums[i]);
        }
        cout<<mp.top()<<endl;
        for(int i=k;i<nums.size();i++)
        {
            int front=mp.top();
            if(nums[i]>front){
                mp.pop();
                mp.push(nums[i]);
            }
        }
        return mp.top();
    }
};