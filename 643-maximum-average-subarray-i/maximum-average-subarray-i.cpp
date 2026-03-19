class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int windowSum = accumulate(nums.begin(), nums.begin() + k, 0);
    
        int maxSum = windowSum;
        for (int i = k; i < nums.size(); ++i) {
            windowSum += nums[i] - nums[i - k];
            
            maxSum = max(maxSum, windowSum);
        }
        return static_cast<double>(maxSum) / k;
    }
};