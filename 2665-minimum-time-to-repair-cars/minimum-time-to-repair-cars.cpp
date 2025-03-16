class Solution {
public:
    bool canRepair(vector<int>& ranks, int cars, long long mid) {
        long long totalCars = 0;

        for (int rank : ranks) {
            totalCars += (long long)sqrt(mid / rank);
            if (totalCars >= cars) {
                return true;
            }
        }
        return false;
    }

    long long repairCars(vector<int>& ranks, int cars) {
        long long st = 0, end = 1LL * *min_element(ranks.begin(), ranks.end()) *
                                cars * cars;
        long long ans;
        while (st <= end) {
            long long mid = st + (end - st) / 2;

            if (canRepair(ranks, cars, mid)) {
                ans = mid;
                end = mid - 1;
            } else {
                st = mid + 1;
            }
        }

        return ans;
    }
};