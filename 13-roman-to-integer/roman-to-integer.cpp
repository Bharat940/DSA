class Solution {
public:
    int romanToInt(string s) {
        int prev = 0;
        int ans = 0;
        for (char ch : s) {
            int curr = (ch == 'I')   ? 1
                       : (ch == 'V') ? 5
                       : (ch == 'X') ? 10
                       : (ch == 'L') ? 50
                       : (ch == 'C') ? 100
                       : (ch == 'D') ? 500
                       : (ch == 'M') ? 1000
                                     : 0;

            if (prev < curr) {
                ans = ans - prev;
                ans = ans + (curr - prev);
            } else {
                ans = ans + curr;
            }

            prev = curr;
        }

        return ans;
    }
};