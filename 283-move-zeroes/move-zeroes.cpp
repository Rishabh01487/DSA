class Solution {
public:
    void moveZeroes(vector<int>& nums) {
    for (int lastNonZero = 0, i = 0; i < nums.size(); ++i)
        if (nums[i] != 0)
            swap(nums[lastNonZero++], nums[i]);
}
};