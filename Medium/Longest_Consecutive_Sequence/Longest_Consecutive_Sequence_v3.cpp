class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;

        unordered_set<int> numSet(nums.begin(), nums.end());
        int longest = 0;

        for (int num : numSet) { // iterate over the set directly (not nums)
            if (!numSet.count(num - 1)) { // only start at the beginning of a sequence
                int currentNum = num;
                int streak = 1;

                while (numSet.count(currentNum + 1)) {
                    currentNum++;
                    streak++;
                }

                longest = max(longest, streak);
            }
        }

        return longest;
    }
};
