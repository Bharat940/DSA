class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int ans = 0, left = 0, right = n - 1;

        int leftMax = 0, rightMax = 0;

        while (left < right) {
            leftMax = max(leftMax, height[left]);
            rightMax = max(rightMax, height[right]);

            if (leftMax < rightMax) {
                ans += leftMax - height[left];
                left++;
            } else {
                ans += rightMax - height[right];
                right--;
            }
        }

        return ans;
    }
};