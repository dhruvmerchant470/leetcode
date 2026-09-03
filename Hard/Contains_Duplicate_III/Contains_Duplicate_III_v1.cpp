class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff,
                                       int valuediff) {
        multiset<int>s;
        int n=nums.size();
        int i = 0;
        for (; i < min(n,indexDiff); i++) {
            if (s.size() > 0) {
                // cout<<nums[i]-valuediff<<endl;
                auto it1 = s.lower_bound(nums[i] - valuediff);
                auto it2 = s.upper_bound(nums[i] + valuediff);
                if ( (it1 != s.end() && abs(*it1 - nums[i]) <= valuediff) ||
                    (it2 != s.begin() &&
                     abs(*prev(it2) - nums[i]) <= valuediff)) {
                    // cout << "h" << endl;
                    return true;
                }
            }
            s.insert(nums[i]);
        }
        for (; i < n; i++) {
            auto it1 = s.lower_bound(nums[i] - valuediff);
            auto it2 = s.upper_bound(nums[i] + valuediff);
            if ( (it1 != s.end() && abs(*it1 - nums[i]) <= valuediff) ||
                (it2 != s.begin() && abs(*prev(it2) - nums[i]) <= valuediff)) {
                // cout << (it1 != s.end()) << endl;
                // cout << "hr" << endl;
                return true;
            }
            s.erase(s.find(nums[i - indexDiff]));
            s.insert(nums[i]);
        }
        return false;
    }
};