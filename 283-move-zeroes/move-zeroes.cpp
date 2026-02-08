#include <bits/stdc++.h>
using namespace std;

// -------- Solution Class --------
class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int n = nums.size();
        int j = 0;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] != 0)
            {
                swap(nums[i], nums[j]);
                j++;
            }
        }
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

    // Call function
    obj.moveZeroes(nums);

    // Output result
    cout << "Array after moving zeroes:\n";
    for (int x : nums)
    {
        cout << x << " ";
    }
    cout << "\n";

    return 0;
}
