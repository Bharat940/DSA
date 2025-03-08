class Solution {
public:

    // Binary search by the recursion

    int binarySearch(vector<int> arr, int target, int st, int end)
    {
    if (st <= end)
    {
        int mid = st + (end - st) / 2;
        if (arr[mid] == target)
        {
            return mid;
        }
        else if (arr[mid] <= target)
        {
            return binarySearch(arr, target, mid + 1, end);
        }
        else
        {
            return binarySearch(arr, target, st, mid - 1);
        }
    }

    return -1;
    }
    int search(vector<int>& nums, int target) {
    //    int left = 0, right = nums.size() - 1;
    //    while(left <= right) {
    //     int mid = left + (right - left)/2;
    //     if(nums[mid] == target) {
    //         return mid;
    //     }
    //     else if(nums[mid] < target) {
    //         left = mid+1;
    //     } 
    //     else {
    //         right = mid -1;
    //     }
    //    }

       return binarySearch(nums, target, 0, nums.size() - 1);
    }
};