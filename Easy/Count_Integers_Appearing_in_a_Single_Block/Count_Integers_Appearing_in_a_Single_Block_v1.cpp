class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        vector<pair<int, int>> tmp;
        for (int i = 0; i < nums.size(); i++)
            tmp.push_back({nums[i], i});
        sort(tmp.begin(), tmp.end());
        int cnt = 0;
        for (int i = 0; i < tmp.size();) {
            int prev = tmp[i].first;
            int prev_idx = tmp[i].second;
            i+=1;
            bool flag = true;
            while(i<tmp.size() && prev == tmp[i].first){
                if(prev_idx+1!=tmp[i].second) flag = false;
                prev_idx = tmp[i].second;
                i+=1;
            }
            if(flag) cnt+=1;
        }
        return cnt;
    }
};