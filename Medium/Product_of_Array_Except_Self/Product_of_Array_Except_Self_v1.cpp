class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        float product=1;
        vector<int> arr(nums.size());
        for(int i=0;i<nums.size();i++)
        arr[i]=1;
        for(int i=0;i<nums.size();i++)
        {   
            if(nums[i]==0){
            for(int j=0;j<nums.size();j++){
                if(j!=i){arr[j]=0;}
            }}
            else{
                product=product*nums[i];
            }
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0&&arr[i]!=0){
                arr[i]=product;
            }
            else{
                if(arr[i]!=0){
                    arr[i]=product/nums[i];
                }
            }
        }
        return arr;
    }
    
};