#define MOD 998244353
#define BASE 26

class Solution {
public:
    // Fast modular exponentiation
    long long mod_pow(long long base, long long exp) {
        long long result = 1;
        base %= MOD;
        while (exp > 0) {
            if (exp & 1) result = result * base % MOD;
            base = base * base % MOD;
            exp >>= 1;
        }
        return result;
    }

    // Only used in case of hash collision
    bool check(const string &a, const string &b, long long i) {
        for (int j = 0; j < a.size(); ++j, ++i)
            if (i >= b.size() || a[j] != b[i])
                return false;
        return true;
    }

    int strStr(string haystack, string needle) {
        int H = haystack.size(), N = needle.size();
        if (N > H) return -1;
        if (N == 0) return 0;

        long long needle_hash = 0, curr_hash = 0;
        long long power = mod_pow(BASE, N - 1);

        for (int i = 0; i < N; ++i) {
            needle_hash = (needle_hash * BASE + (needle[i] - 'a')) % MOD;
            curr_hash = (curr_hash * BASE + (haystack[i] - 'a')) % MOD;
        }

        if (curr_hash == needle_hash && check(needle, haystack, 0))
            return 0;

        for (int i = N; i < H; ++i) {
            // Remove leading character and add trailing one
            curr_hash = (curr_hash - (haystack[i - N] - 'a') * power % MOD + MOD) % MOD;
            curr_hash = (curr_hash * BASE + (haystack[i] - 'a')) % MOD;

            if (curr_hash == needle_hash && check(needle, haystack, i - N + 1))
                return i - N + 1;
        }

        return -1;
    }
};
