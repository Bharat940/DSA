class Solution {
public:
    bool checkPerfectNumber(int num) {
        if (num <= 1) {
            return false;
        }

        int ans = 1;

        for (int i = 2; i * i <= num; i++) {
            if (num % i == 0) {
                ans = ans + i;
                if (i != num / i) {
                    ans += num / i;
                }
            }
        }

        return num == ans;
    }
};