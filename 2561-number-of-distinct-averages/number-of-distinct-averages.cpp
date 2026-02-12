class Solution {
public:
    int distinctAverages(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int l = 0, r = nums.size() - 1;
        unordered_set<double> avgSet;
        while (l < r) {
            double avg = (nums[l] + nums[r]) / 2.0;
            avgSet.insert(avg);
            l++; r--;
        }
        return avgSet.size();
    }
};