class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int count = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int j = i + 1, k = n - 1;
            while (j < k) {
                if (nums[j] - nums[i] == diff && nums[k] - nums[j] == diff) {
                    count++;
                    j++; k--;
                } else if (nums[j] - nums[i] < diff) j++;
                else if (nums[k] - nums[j] > diff) k--;
                else { j++; k--; }
            }
        }
        return count;
    }
};