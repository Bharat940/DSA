class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int st = 0, end = letters.size() - 1;
        int idx = 0;

        while(st <= end) {
            int mid = st + (end - st)/2;

            if(letters[mid] > target) {
                idx = mid;
                end = mid -1;
            } else  {
                st = mid+1;
            }
        }
        return letters[idx];
    }
};