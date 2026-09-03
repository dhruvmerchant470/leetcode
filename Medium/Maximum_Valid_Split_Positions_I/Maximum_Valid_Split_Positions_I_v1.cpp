class Solution {
public:
    int gcd(int a, int b) {
        if (a % b == 0)
            return b;
        return gcd(b, a % b);
    }
    int maxValidSplits(vector<int>& nums) {
        // without removing
        int n = nums.size();
        vector<int> pref(n);
        vector<int> suff(n);
        pref[0] = nums[0];
        for (int i = 1; i < n; i++)
            pref[i] = gcd(nums[i], pref[i - 1]);
        suff[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i -= 1)
            suff[i] = gcd(suff[i + 1], nums[i]);
        int t = 0;
        for (int i = 0; i < n - 1; i++) {
            if (pref[i] == suff[i + 1])
                t += 1;
        }

        // removing 1 element

        for (int j = 0; j < n; j++) {
            vector<int> pref1(n - 1);
            vector<int> suff1(n - 1);
            vector<int> tmp;
            for (int i = 0; i < n; i++) {
                if (i != j)
                    tmp.push_back(nums[i]);
            }
            pref1[0] = tmp[0];
            for (int i = 1; i < n-1; i++)
                pref1[i] = gcd(tmp[i], pref1[i - 1]);
            suff1[n - 2] = tmp[n - 2];
            for (int i = n - 3; i >= 0; i -= 1)
                suff1[i] = gcd(suff1[i + 1], tmp[i]);
            int t1 = 0;
            for (int i = 0; i < n - 2; i++) {
                if (pref1[i] == suff1[i + 1])
                    t1 += 1;
            }
            t = max(t,t1);
        }
        return t;
    }
};