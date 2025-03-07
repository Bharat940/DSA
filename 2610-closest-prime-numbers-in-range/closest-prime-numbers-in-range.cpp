class Solution {
public:

    bool isPrime(int n) {
        if(n < 2) return false;
        for(int i = 2; i * i <= n; i++) {
            if(n % i == 0) return false;
        }
        return true;
    }

    vector<int> closestPrimes(int left, int right) {
      int num1 = -1, num2 = -1, prevPrime = -1;
      int minDiff = INT_MAX;
      
      for(int i = left; i <= right; i++) {
        if(isPrime(i)) {
            if(prevPrime != -1 && (i - prevPrime) < minDiff) {
                minDiff = (i - prevPrime);
                num1 = prevPrime;
                num2 = i;
            }
            prevPrime = i;
        }
      } 

      if(num1 == -1) return {-1, -1};
      return {num1, num2};
    }
};