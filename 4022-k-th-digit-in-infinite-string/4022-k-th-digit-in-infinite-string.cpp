class Solution {
public:
    long long digits(long long n) {
        long long res = 0;
        long long p = 1;
        while (p <= n) {
            long long next = min(n, p * 10 - 1);
            res += (next - p + 1) * to_string(p).size();
            p *= 10;
        }
        return res;
    }
    int kthDigit(long long k) {
        if (k <= 9)
            return k;
        k -= 9;
        long long lo = 1, hi = 1;

        while (digits(10 * hi + 9) - 9 < k)
            hi *= 2;

        while (lo < hi) {
            long long mid = (lo + hi) / 2;

            if (digits(10 * mid + 9) - 9 >= k)
                hi = mid;
            else
                lo = mid + 1;
        }
        long long b = lo;
        long long before = digits(10 * (b - 1) + 9) - 9;
        long long pos = k - before - 1;
        long long index = pos / to_string(10 * b).size();
        if (b % 2 == 1)
            index = 9 - index;
        long long number = 10 * b + index;
        int digitPos = pos % to_string(number).size();
        return to_string(number)[digitPos] - '0';
    }
};