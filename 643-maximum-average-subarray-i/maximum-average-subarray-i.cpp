class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int maxSum = INT_MIN;
        int sum = 0, left = 0;
        for (int right = 0; right < nums.size(); ++right) {
            sum += nums[right];
            if (right - left + 1 == k)
             {
                maxSum = (maxSum > sum) ? maxSum : sum;
                sum -= nums[left];
                left++;
            }
        }
        return (double)maxSum / k;
    }
};