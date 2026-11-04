class Solution {
public:
    string decodeString(string s) {
        stack<int> counts;
        stack<string> strs;
        string cur;
        int num = 0;
        for (char c : s) {
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            } else if (c == '[') {
                counts.push(num);
                strs.push(cur);
                num = 0;
                cur = "";
            } else if (c == ']') {
                string t = strs.top(); strs.pop();
                int k = counts.top(); counts.pop();
                while (k--) t += cur;
                cur = t;
            } else {
                cur += c;
            }
        }
        return cur;
    }
};