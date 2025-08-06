class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int count = 0;

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] >= k)
                continue;
            count++;
            int multiple = nums[i];
            for (int j = i + 1; j < nums.size(); ++j) {
                if (nums[j] >= k || (multiple * nums[j]) >= k) {
                    break;
                }
                multiple *= nums[j];
                count++;
            }
        }
        return count;
    }
};