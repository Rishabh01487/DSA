class Solution {
public:
    vector<vector<int>> ans;
    vector<int> subset;

    void backtrack(int idx, vector<int>& nums) {
        ans.push_back(subset);

        for (int i = idx; i < nums.size(); i++) {
            subset.push_back(nums[i]);
            backtrack(i + 1, nums);
            subset.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        backtrack(0, nums);
        return ans;
    }
};