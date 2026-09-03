class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int maj = INT_MIN;
        int cnt = 0;
        for (auto elt : nums) {
            if (cnt == 0)
                maj = elt;
            if (elt == maj) {
                cnt++;
            } else
                cnt--;
        }
        return maj;
    }
};