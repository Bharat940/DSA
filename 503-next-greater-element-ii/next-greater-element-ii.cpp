#include <bits/stdc++.h>
using namespace std;

// -------- Solution Class --------
class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans(n, -1);

        stack<int> s;

        // Traverse twice (circular array simulation)
        for (int i = 2 * n - 1; i >= 0; i--)
        {

            while (!s.empty() && nums[s.top()] <= nums[i % n])
            {
                s.pop();
            }

            if (i < n)
            { // Fill answer only in first pass
                ans[i] = s.empty() ? -1 : nums[s.top()];
            }

            s.push(i % n);
        }

        return ans;
    }
};

// -------- Driver / Main --------
int main()
{
    Solution obj;

    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    vector<int> result = obj.nextGreaterElements(nums);

    cout << "Next Greater Elements:\n";
    for (int x : result)
    {
        cout << x << " ";
    }
    cout << "\n";

    return 0;
}
