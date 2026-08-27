class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int> freq(k, 0);
        freq[0] = 1;

        int prefix = 0;
        int ans = 0;

        for (int x : nums) {
            prefix = (prefix + x) % k;

            if (prefix < 0)
                prefix += k;

            ans += freq[prefix];
            freq[prefix]++;
        }

        return ans;
    }
};