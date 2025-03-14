class Solution {
public:
    bool canAssign(vector<int>& candies, long long mid, long long k) {
        long long count = 0;
        for (long long element : candies) {
            if (element >= mid) {
                count += element / mid;
            }
        }

        return count >= k;
    }

    int maximumCandies(vector<int>& candies, long long k) {
        long long st = 1;
        long long end = *max_element(candies.begin(), candies.end());

        long long max_candies = 0;
        while (st <= end) {
            long long mid = st + (end - st) / 2;
            if (canAssign(candies, mid, k)) {
                max_candies = mid;
                st = mid + 1;
            } else {
                end = mid - 1;
            }
        }

        return max_candies;
    }
};