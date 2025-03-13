class Solution {
public:
    bool canBecomeZero(const vector<int>& nums,
                       const vector<vector<int>>& queries, int k) {
        int n = nums.size();
        vector<long long> prefixSum(n + 1, 0);

        // Apply the first k queries
        for (int i = 0; i < k; ++i) {
            int l = queries[i][0];
            int r = queries[i][1];
            int v = queries[i][2];
            prefixSum[l] += v;
            if (r + 1 < n) {
                prefixSum[r + 1] -= v;
            }
        }

        long long currEffect = 0;
        for (int i = 0; i < n; ++i) {
            currEffect += prefixSum[i];
            if (nums[i] - currEffect > 0) {
                return false;
            }
        }
        return true;
    }

    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int m = queries.size();

        int left = 0, right = m;
        int result = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canBecomeZero(nums, queries, mid)) {
                result = mid;
                right = mid - 1; // Try to find a smaller k
            } else {
                left = mid + 1;
            }
        }

        return result;
    }
};