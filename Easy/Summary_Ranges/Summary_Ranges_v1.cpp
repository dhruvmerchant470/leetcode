class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        for (int i = 0; i < nums.size(); i++) {
            int tmp = nums[i];
            int pre_i = i;
            string ans = to_string(nums[i]);
            while (i + 1 < nums.size() && tmp + 1 == nums[i + 1]) {
                tmp = nums[i + 1];
                i++;
            }
            if (pre_i != i) {
                ans += "->";
                ans += to_string(tmp);
            }
            res.push_back(ans);
        }
        return res;
    }
};