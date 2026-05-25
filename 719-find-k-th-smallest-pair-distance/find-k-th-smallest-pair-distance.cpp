class Solution {
public:
    int countPairs(vector<int>& nums, int mid) {
        int cnt = 0;
        int j = 0;

        for(int i = 0; i < nums.size(); i++) {
            while(j < nums.size() && nums[j] - nums[i] <= mid) {
                j++;
            }

            cnt += (j - i - 1);
        }

        return cnt;
    }

    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int low = 0;
        int high = nums[nums.size() - 1] - nums[0];

        while(low < high) {
            int mid = low + (high - low) / 2;

            if(countPairs(nums, mid) >= k) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};