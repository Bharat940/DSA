#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int n = nums.size();
        int left = 0, right = n - 1, start = -1, end = -1;
        vector<int> ans;

        // Find start index (lower bound)
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] >= target)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }

        if (left < n && nums[left] == target)
        {
            start = left;
        }
        else
        {
            ans.push_back(start);
            ans.push_back(end);
            return ans;
        }

        // Find end index (upper bound)
        right = n - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] <= target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        end = right;

        ans.push_back(start);
        ans.push_back(end);
        return ans;
    }
};

// -------- Driver / Main --------
int main()
{
    Solution obj;

    // Example input
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 8;

    vector<int> ans = obj.searchRange(nums, target);

    cout << "Start: " << ans[0] << "\n";
    cout << "End: " << ans[1] << "\n";

    return 0;
}
