class Solution {
public:
    int countDigits(int x) {
        int count = 0;
        while (x > 0) {
            x /= 10;
            count++;
        }

        return count;
    }

    int findNumbers(vector<int>& nums) {
        int evenDigits = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (countDigits(nums[i]) % 2 == 0) {
                evenDigits++;
            }
        }
        return evenDigits;
    }
};