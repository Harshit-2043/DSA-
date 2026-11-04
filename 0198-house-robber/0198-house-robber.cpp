class Solution {
public:
    int rob(vector<int>& nums) {
        int prev = 0, cur = 0;
        for (int x : nums) {
            int t = max(cur, prev + x);
            prev = cur;
            cur = t;
        }
        return cur;
    }
};