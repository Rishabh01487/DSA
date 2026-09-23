class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        vector<long long> prefix(nums.size() + 1, 0);

        for (int i = 0; i < nums.size(); i++)
            prefix[i + 1] = prefix[i] + nums[i];

        return mergeSort(prefix, 0, prefix.size(), lower, upper);
    }

    long long mergeSort(vector<long long>& prefix, int left, int right, int lower, int upper) {
        if (right - left <= 1)
            return 0;

        int mid = left + (right - left) / 2;

        long long count = mergeSort(prefix, left, mid, lower, upper)
                        + mergeSort(prefix, mid, right, lower, upper);

        int j = mid, k = mid;

        for (int i = left; i < mid; i++) {
            while (j < right && prefix[j] - prefix[i] < lower)
                j++;

            while (k < right && prefix[k] - prefix[i] <= upper)
                k++;

            count += k - j;
        }

        vector<long long> temp;
        int i = left;
        j = mid;

        while (i < mid && j < right) {
            if (prefix[i] <= prefix[j])
                temp.push_back(prefix[i++]);
            else
                temp.push_back(prefix[j++]);
        }

        while (i < mid)
            temp.push_back(prefix[i++]);

        while (j < right)
            temp.push_back(prefix[j++]);

        for (int p = 0; p < temp.size(); p++)
            prefix[left + p] = temp[p];

        return count;
    }
};