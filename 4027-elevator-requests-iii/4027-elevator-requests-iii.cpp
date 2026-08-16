class Solution {
public:
    long long elevatorRequests(int n, int start, vector<vector<int>>& requests) {
        int m = requests.size();
        int N = 1 << m;
        const long long INF = 4e18;

        vector<int> floor(m), arrival(m);
        for (int i = 0; i < m; i++) {
            arrival[i] = requests[i][0];
            floor[i] = requests[i][1];
        }

        vector<vector<long long>> dp(N, vector<long long>(m, INF));

        for (int i = 0; i < m; i++) {
            long long t = abs(start - floor[i]);
            t = max(t, (long long)arrival[i]);

            int mask = 0;
            for (int j = 0; j < m; j++) {
                long long d = abs(start - floor[j]);
                if (floor[j] >= min(start, floor[i]) &&
                    floor[j] <= max(start, floor[i]) &&
                    arrival[j] <= d)
                    mask |= 1 << j;
            }

            dp[mask][i] = min(dp[mask][i], t);
        }

        for (int mask = 0; mask < N; mask++) {
            for (int i = 0; i < m; i++) {
                if (dp[mask][i] == INF) continue;

                long long cur = dp[mask][i];

                for (int j = 0; j < m; j++) {
                    if (mask & (1 << j)) continue;

                    long long dist = abs(floor[i] - floor[j]);
                    long long nt = cur + dist;
                    nt = max(nt, (long long)arrival[j]);

                    int nmask = mask;

                    for (int k = 0; k < m; k++) {
                        if (mask & (1 << k)) continue;

                        if (floor[k] >= min(floor[i], floor[j]) &&
                            floor[k] <= max(floor[i], floor[j])) {
                            long long pt = cur + abs(floor[i] - floor[k]);

                            if (floor[k] == floor[j])
                                pt = nt;

                            if (pt >= arrival[k])
                                nmask |= 1 << k;
                        }
                    }

                    dp[nmask][j] = min(dp[nmask][j], nt);
                }
            }
        }

        return *min_element(dp[N - 1].begin(), dp[N - 1].end());
    }
};