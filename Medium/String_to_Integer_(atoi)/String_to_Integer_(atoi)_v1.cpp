class Solution {
public:
    int myAtoi(string s) {
        int index = 0;
        while (s[index] == ' ')
            index++;
        char sign = '+';
        if (s[index] == '-') {
            sign = '-';
            index++;
        } else if (s[index] == '+') {
            index++;
        }
        int prev_index = index;
        while (s[index] >= '0' && s[index] <= '9') {
            index++;
        }
        while (s[prev_index] == '0')
            prev_index++;
        index--;
        long long int ans = 0;
        if (1LL * pow(10, index - prev_index) > INT_MAX)
            return sign == '-' ? -(1LL * INT_MAX + 1) : INT_MAX;
        long long int ten = 1LL * pow(10, index - prev_index);
        bool flag = 0;
        while (prev_index <= index) {
            int tmp = s[prev_index] - '0';
            ans = ans + tmp * ten;
            if (ans > INT_MAX) {
                if (sign == '-')
                    ans = 1LL * INT_MAX + 1;
                else
                    ans = INT_MAX;
                flag = 1;
                break;
            }
            ten /= 10;
            prev_index++;
        }
        cout << ans << " " << flag << " " << sign << endl;
        return sign == '-' ? -ans : ans;
    }
};