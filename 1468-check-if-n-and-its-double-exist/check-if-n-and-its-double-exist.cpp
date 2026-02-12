class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        for (int i = 0; i < arr.size(); i++) {
            int target = 2 * arr[i];
            int lo = 0, hi = arr.size() - 1;
            while (lo <= hi) {
                int mid = lo + (hi - lo) / 2;
                if (arr[mid] == target && mid != i) return true;
                else if (arr[mid] < target) lo = mid + 1;
                else hi = mid - 1;
            }
        }
        return false;
    }
};