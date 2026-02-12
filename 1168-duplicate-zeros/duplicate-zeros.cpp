class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n = arr.size();
        int zeros = count(arr.begin(), arr.end(), 0);
        int i = n - 1, j = n + zeros - 1;
        while (i >= 0) {
            if (j < n) arr[j] = arr[i];
            j--;
            if (arr[i] == 0) {
                if (j < n) arr[j] = 0;
                j--;
            }
            i--;
        }
    }
};