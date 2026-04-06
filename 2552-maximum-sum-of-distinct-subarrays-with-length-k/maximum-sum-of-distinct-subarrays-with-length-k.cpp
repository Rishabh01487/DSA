class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        long long currentSum = 0;
        long long maxSum = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            currentSum += nums[i];
            freq[nums[i]]++;
            
            if (i >= k) {
                int leftElement = nums[i - k];
                currentSum -= leftElement;
                freq[leftElement]--;
                if (freq[leftElement] == 0) {
                    freq.erase(leftElement);
                }
            }
            
            if (freq.size() == k) {
                maxSum = max(maxSum, currentSum);
            }
        }
        
        return maxSum;
    }
};