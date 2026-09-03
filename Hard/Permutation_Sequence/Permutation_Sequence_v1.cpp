class Solution {
public:
    string getPermutation(int n, int k) {
        // Factorial lookup table for quick computation
        vector<int> factorial(n + 1, 1);
        for (int i = 2; i <= n; ++i) {
            factorial[i] = factorial[i - 1] * i;
        }
        
        // Digits to form the permutation
        vector<char> digits;
        for (int i = 1; i <= n; ++i) {
            digits.push_back('0' + i);
        }
        
        string result;
        k--; // Convert k to 0-indexed
        
        while (n > 0) {
            int index = k / factorial[n - 1];
            result += digits[index];
            digits.erase(digits.begin() + index);
            k %= factorial[n - 1];
            n--;
        }
        
        return result;
    }
};
