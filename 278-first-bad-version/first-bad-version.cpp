#include <bits/stdc++.h>
using namespace std;


// -------- Mock API --------
// Change this value to simulate first bad version
int BAD_VERSION = 4;

bool isBadVersion(int version) {
    return version >= BAD_VERSION;
}


// -------- Solution Class --------
class Solution {
public:
    int firstBadVersion(int n) {
        int st = 1, end = n;
        int ans = n;

        while (st <= end) {
            int mid = st + (end - st) / 2;

            if (isBadVersion(mid)) {
                ans = mid;
                end = mid - 1;
            } else {
                st = mid + 1;
            }
        }

        return ans;
    }
};


// -------- Driver / Main --------
int main() {
    Solution obj;

    int n;
    cout << "Enter total versions: ";
    cin >> n;

    int result = obj.firstBadVersion(n);

    cout << "First Bad Version: " << result << "\n";

    return 0;
}
