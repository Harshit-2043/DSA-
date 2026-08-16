class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        while (i < s.size() && s[i] == ' ')
            i++;
        int sign = 1;
        if (i < s.size() && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-')
                sign = -1;
            i++;
        }
        long long num = 0;
        while (i < s.size() && isdigit(s[i])) {
            if (num > INT_MAX / 10 ||
               (num == INT_MAX / 10 && s[i] - '0' > 7))
                return sign == 1 ? INT_MAX : INT_MIN;
            num = num * 10 + (s[i] - '0');
            i++;
        }
        return sign * num;
    }
};