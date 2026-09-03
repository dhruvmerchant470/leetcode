class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int s=0,e=nums.size()-1,mid=s+(e-s)/2,ans=-1;
        int mid1=s+(e-s)/2,ans1=-1;
        while(mid1!=s-1)
        {
            int sum1=0,sum2=0;
            for(int i=0;i<mid1;i++)
            {
                sum1+=nums[i];
            }
            for(int i=mid1+1;i<e+1;i++)
            {
                sum2+=nums[i];
            }
            if(sum1==sum2){ ans1=mid1;mid1--;}
            else mid1--;
        }
        if(ans1!=-1)
        {
            return ans1;
        }
        while(mid!=e+1)
        {
            int sum1=0,sum2=0;
            for(int i=0;i<mid;i++)
            {
                sum1+=nums[i];
            }
            for(int i=mid+1;i<e+1;i++)
            {
                sum2+=nums[i];
            }
            if(sum1==sum2) {ans=mid;mid++;break;}
            else mid++;
        }
        if(ans!=-1)
        {
            return ans;
        }
        
        return ans;
    }
};