class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, int> freq;
        vector<int> res;

        for (int element : nums) {
            freq[element]++;
        }

        for (auto it : freq) {
            int element = it.first;
            int count = it.second;

            if (count > n / 3) {
                res.push_back(element);
            }
        }

        if (res.size() == 2 && res[0] > res[1])
            swap(res[0], res[1]);
        return res;
    }
};