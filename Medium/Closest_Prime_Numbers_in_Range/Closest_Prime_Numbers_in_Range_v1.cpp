class Solution {
public:
    bool prime(int n){
        if(n<=1) return false;
        for(int i=2;i<=sqrt(n);i++) if(n%i==0) return false;
        return true;
    }
    vector<int> closestPrimes(int left, int right) {
        vector<int>primes;
        for(int i=left;i<=right;i++){
            if(prime(i)) primes.push_back(i);
        }
        int mini=INT_MAX;
        vector<int>ans={-1,-1};
        for(int i=0;i<(int)primes.size()-1;i++){
            if(primes[i+1]-primes[i]<mini) {
                mini=primes[i+1]-primes[i];
                ans={primes[i],primes[i+1]};
            }
        }
        return ans;
    }
};