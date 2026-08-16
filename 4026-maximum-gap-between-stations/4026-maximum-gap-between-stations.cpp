class Solution {
public:
    int maximumGap(string skill, string station) {
        int n = skill.size();
        int m = station.size();

        if (n == 1) return 0;

        vector<int> left(n), right(n);

        int p = 0;
        for (int i = 0; i < n; i++) {
            while (station[p] != skill[i]) p++;
            left[i] = p++;
        }

        p = m - 1;
        for (int i = n - 1; i >= 0; i--) {
            while (station[p] != skill[i]) p--;
            right[i] = p--;
        }

        int ans = 0;

        for (int i = 1; i < n; i++) {
            ans = max(ans, right[i] - left[i - 1]);
        }

        return ans;
    }
};