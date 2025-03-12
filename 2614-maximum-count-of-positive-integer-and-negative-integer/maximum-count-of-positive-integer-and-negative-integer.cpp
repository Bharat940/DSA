class Solution {
public:
    int maximumCount(vector<int>& nums) {
    int left = 0, right = nums.size() - 1;
        int firstNonNegative = nums.size(); 
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < 0) {
                left = mid + 1;
            } else { 
                firstNonNegative = mid;
                right = mid - 1;
            }
        }
        
        int negCount = firstNonNegative;
        
        left = 0;
        right = nums.size() - 1;
        int firstPositive = nums.size();
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] <= 0) {
                left = mid + 1;
            } else { 
                firstPositive = mid;
                right = mid - 1;
            }
        }
        
        int posCount = nums.size() - firstPositive;
        
        return max(negCount, posCount);
    }
};