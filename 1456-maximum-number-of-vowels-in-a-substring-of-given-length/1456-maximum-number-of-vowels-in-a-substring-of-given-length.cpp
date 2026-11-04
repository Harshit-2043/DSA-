class Solution {
public:
    int maxVowels(string s, int k) {
        auto isV = [](char c) {
            return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
        };
        int cnt = 0, best = 0;
        for (int i = 0; i < s.size(); i++) {
            if (isV(s[i])) cnt++;
            if (i >= k && isV(s[i - k])) cnt--;
            best = max(best, cnt);
        }
        return best;
    }
};