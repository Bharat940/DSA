class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0, right = n-1, start = -1, end = -1;
        vector<int> ans;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(nums[mid] >= target) {
                right = mid -1;
            } else {
                left = mid + 1;
            }
        }

        if(left < n && nums[left] == target ) {
            start = left;
        } else {
            ans.push_back(start);
            ans.push_back(end);
            return ans;
        }

        right = n - 1;
        while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] <= target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
        }
        end = right;
        ans.push_back(start);
        ans.push_back(end);
        return ans;
    }
};