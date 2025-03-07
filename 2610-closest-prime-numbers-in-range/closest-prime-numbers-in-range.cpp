class Solution {
public:

    vector<bool> sieve(int n) {
        vector<bool> isPrime(n + 1, true);
        isPrime[0] = isPrime[1] = false;

        for(int i = 2; i * i <= n; i++) {
            if(isPrime[i]) {
                for(int j = i * i; j <= n; j+=i) {
                    isPrime[j] = false;
                }
            }
        }

        return isPrime;
    }

    vector<int> closestPrimes(int left, int right) {
      int num1 = -1, num2 = -1, prevPrime = -1;
      int minDiff = INT_MAX;
        vector<bool> isPrime = sieve(right);
      for(int i = left; i <= right; i++) {
        if(isPrime[i]) {
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