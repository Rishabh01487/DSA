class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMostK(nums, k) - atMostK(nums, k - 1);
    }
private:
    int atMostK(vector<int>& nums, int k) {
        int left = 0, res = 0;
        unordered_map<int, int> count;
        for (int right = 0; right < nums.size(); ++right) {
            count[nums[right]]++;
            while (count.size() > k) {
                count[nums[left]]--;
                if (count[nums[left]] == 0) count.erase(nums[left]);
                left++;
            }
            res += right - left + 1;
        }
        return res;
    }
};