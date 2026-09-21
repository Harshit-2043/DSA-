class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> ans(k), dp(k);

        for (int num : nums) {
            int x = num % k;
            vector<long long> ndp(k);

            ndp[x] = 1;

            for (int r = 0; r < k; r++) {
                int nr = (r * x) % k;
                ndp[nr] += dp[r];
            }

            for (int r = 0; r < k; r++)
                ans[r] += ndp[r];

            dp = ndp;
        }

        return ans;
    }
};