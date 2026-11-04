class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int windowSum = 0;
        for (int i = 0; i < k; i++) {
            windowSum += nums[i];
        }
        int maxSum = windowSum;
        for (int right = k; right < nums.size(); right++) {
            windowSum += nums[right];
            windowSum -= nums[right - k];

            maxSum = max(maxSum, windowSum);
        }
        return (double)maxSum / k;
    }
};