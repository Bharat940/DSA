class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size(), count = 0;
        int alt = 1;
        int prev = colors[0];

        for (int i = 1; i < (n + k - 1); i++) {
            alt = (prev == colors[i % n]) ? 1 : alt + 1;
            if (alt >= k) {
                count++;
            }
            prev = colors[i % n];
        }
        return count;
    }
};