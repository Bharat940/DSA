class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int ele1 = -1, ele2 = -1, count1 = 0, count2 = 0;

        for (int ele : nums) {
            if (ele1 == ele) {
                count1++;
            } else if (ele2 == ele) {
                count2++;
            } else if (count1 == 0) {
                ele1 = ele;
                count1++;
            } else if (count2 == 0) {
                ele2 = ele;
                count2++;
            } else {
                count1--;
                count2--;
            }
        }

        vector<int> res;
        count1 = 0;
        count2 = 0;

        for (int ele : nums) {
            if (ele1 == ele)
                count1++;
            if (ele2 == ele)
                count2++;
        }

        if (count1 > n / 3)
            res.push_back(ele1);
        if (count2 > n / 3 && ele1 != ele2)
            res.push_back(ele2);

        if (res.size() == 2 && res[0] > res[1])
            swap(res[0], res[1]);
        return res;
    }
};