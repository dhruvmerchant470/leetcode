class Solution {
public:
    long long gcd(int a,int b){
        if(b==0) return a;
        return gcd(b,a%b);
    }
    long long gcdSum(vector<int>& nums) {
        int maxi = -1;
        vector<long long>prefix(nums.size());
        for(int i=0;i<nums.size();i++){
            maxi = max(maxi,nums[i]);
            prefix[i]=gcd(maxi,nums[i]);
        }
        sort(prefix.begin(),prefix.end());
        int i=0,j=prefix.size()-1;
        long long sum = 0;
        while(i<j){
            sum+=gcd(prefix[i++],prefix[j--]);
        }
        return sum;
    }
};