class Solution {
public:
    int gcd(int a,int b){
        if(b==0) return a;
        else return gcd(b,a%b); 
    }
    int findGCD(vector<int>& nums) {
        int maxi = INT_MIN;
        int mini = INT_MAX;
        for(auto &num : nums){
            maxi = max(num,maxi);
            mini = min(num,mini);
        }
        return gcd(mini,maxi);
    }
};