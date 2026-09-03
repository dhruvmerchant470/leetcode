class FindSumPairs {
private:
    vector<int> b;
    unordered_map<int, int> mpA;  // freq map for nums1
    unordered_map<int, int> mpB;  // freq map for nums2

public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        for (int num : nums1) {
            mpA[num]++;
        }
        for (int num : nums2) {
            mpB[num]++;
        }
        b = nums2;
    }
    
    void add(int index, int val) {
        int oldVal = b[index];
        int newVal = oldVal + val;
        mpB[oldVal]--;
        if (mpB[oldVal] == 0) {
            mpB.erase(oldVal);  // optional: cleanup to save space
        }
        mpB[newVal]++;
        b[index] = newVal;
    }
    
    int count(int tot) {
        int ans = 0;
        for (auto& [numA, freqA] : mpA) {
            int complement = tot - numA;
            if (mpB.count(complement)) {
                ans += freqA * mpB[complement];
            }
        }
        return ans;
    }
};
