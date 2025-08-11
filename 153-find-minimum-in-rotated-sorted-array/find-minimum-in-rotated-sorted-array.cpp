class Solution {
public:
    int findMin(vector<int>& nums) {
        int min = 6900, left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (min > nums[mid])
                min = nums[mid];

            if (nums[left] <= nums[mid] && nums[right] <= nums[left]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return min;
    }
};