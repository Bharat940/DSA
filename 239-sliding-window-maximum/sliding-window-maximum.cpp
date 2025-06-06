class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;

        // 1st window
        for (int i = 0; i < k; i++) {
            while (dq.size() > 0 && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }

        for (int i = k; i < nums.size(); i++) {
            ans.push_back(nums[dq.front()]);

            // remove not part of curr wind
            while (dq.size() > 0 && dq.front() <= i - k) {
                dq.pop_front();
            }

            // remove smaller vals
            while (dq.size() > 0 && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }

            dq.push_back(i);
        }

        ans.push_back(nums[dq.front()]);

        return ans;
    }
};