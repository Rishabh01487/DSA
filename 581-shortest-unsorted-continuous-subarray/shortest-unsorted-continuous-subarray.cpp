class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        
        int n = nums.size();
        int start = -1, end = -2;

        int min_val = nums[n-1];
        int max_val = nums[0];

        for(int i = 1; i < n; i++) {
            max_val = max(max_val, nums[i]);
            if(nums[i] < max_val)
                end = i;
        }

        for(int i = n-2; i >= 0; i--) {
            min_val = min(min_val, nums[i]);
            if(nums[i] > min_val)
                start = i;
        }

        return end - start + 1;
    }
};