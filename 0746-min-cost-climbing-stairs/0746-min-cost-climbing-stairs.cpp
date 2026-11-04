class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int a = 0, b = 0;
        for (int i = 2; i <= cost.size(); i++) {
            int c = min(b + cost[i - 1], a + cost[i - 2]);
            a = b;
            b = c;
        }
        return b;
    }
};