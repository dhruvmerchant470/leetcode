class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res=0;
        for(int i=0;i<32;i++){
            int tmp=1<<i;
            int cnt=0;
            for(auto it: nums){
                if(it&tmp) cnt++;
            }
            if(cnt%3==1){
                res|=tmp;
            }
        }
        return res;
    }
};