class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2,
                               int k1, int k2) {
        long long k = 1LL * k1 + k2;
        vector<long long> diff;
        long long maxDiff = 0, totalDiff = 0;

        for (int i = 0; i < nums1.size(); ++i) {
            long long d = llabs(1LL * nums1[i] - nums2[i]);
            diff.push_back(d);
            maxDiff = max(maxDiff, d);
            totalDiff += d;
        }

        // Extra operations have no effect once all differences are zero.
        k = min(k, totalDiff);

        auto operationsNeeded = [&](long long level) {
            long long needed = 0;
            for (long long d : diff) {
                needed += max(0LL, d - level);
                if (needed > k) return needed;
            }
            return needed;
        };

        long long lo = 0, hi = maxDiff;
        while (lo < hi) {
            long long mid = lo + (hi - lo) / 2;
            if (operationsNeeded(mid) <= k)
                hi = mid;
            else
                lo = mid + 1;
        }

        long long level = lo;
        long long used = operationsNeeded(level);
        long long remaining = k - used;

        long long result = 0;
        for (long long d : diff) {
            long long capped = min(d, level);
            result += capped * capped;
        }

        // Use remaining operations to lower that many values from level to level - 1.
        if (level > 0)
            result -= remaining * (2 * level - 1);

        return result;
    }
};