class Solution {
public:
    int maximumCount(vector<int>& nums) {
    //    int st = 0, end = nums.size() - 1;
    int negCount = 0, posCount = 0;
    for(int i = 0; i < nums.size(); i++) {
        if(nums[i] < 0) {
            negCount++;
        } else if(nums[i] > 0) {
            posCount++;
        } 
    }  
    int ans = max(negCount, posCount);

    return ans;
    }
};