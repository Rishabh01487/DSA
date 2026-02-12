class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        for (auto& row : image) {
            int left = 0, right = row.size() - 1;
            while (left <= right) {
                swap(row[left], row[right]);
                row[left] ^= 1;
                if (left != right) row[right] ^= 1;
                left++;
                right--;
            }
        }
        return image;
    }
};