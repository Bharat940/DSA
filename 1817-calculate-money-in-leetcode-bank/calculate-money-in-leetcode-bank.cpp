class Solution {
public:
    int totalMoney(int n) {
        int k = n / 7;
        int firstElement = 28;
        int lastElement = 28 + (k - 1) * 7;
        int sum = k * (firstElement + lastElement) /2;

        int monday  = 1 + k;
        int finalWeek = 0;
        for (int i = 0; i < n % 7; i++) {
            finalWeek = finalWeek + monday + i;
        }
        
        return sum + finalWeek;
    }
};