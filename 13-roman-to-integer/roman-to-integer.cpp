class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> roman_values = {
            {'I', 1},   {'V', 5},   {'X', 10},  {'L', 50},
            {'C', 100}, {'D', 500}, {'M', 1000}};

        int ans = roman_values[s.back()];

        for (int i = s.size() - 2; i >= 0; i--) {
            if (roman_values[s[i]] < roman_values[s[i + 1]]) {
                ans = ans - roman_values[s[i]];
            } else {
                ans = ans + roman_values[s[i]];
            }
        }

        return ans;
    }
};