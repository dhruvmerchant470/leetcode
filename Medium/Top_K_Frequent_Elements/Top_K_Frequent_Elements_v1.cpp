class Solution {
public:
    static bool sortByValue(const std::pair<int, int>& a,
                            const std::pair<int, int>& b) {
        return a.second > b.second;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        map<int, int> map1;
        for (int i = 0; i < nums.size(); i++) {
            map1[nums[i]] = map1[nums[i]] + 1;
        }
        std::vector<std::pair<int, int>> vec(map1.begin(), map1.end());

        std::sort(vec.begin(), vec.end(), sortByValue);

        for (int i = 0; i < k; i++) {
            ans.push_back(vec[i].first);
        }

        return ans;
    }
};