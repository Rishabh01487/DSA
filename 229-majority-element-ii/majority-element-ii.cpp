class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int freqA = 0, freqB = 0;
        int candA = 0, candB = 1;

        for (int val : nums) {
            if (val == candA) {
                freqA++;
            } else if (val == candB) {
                freqB++;
            } else if (freqA == 0) {
                candA = val;
                freqA = 1;
            } else if (freqB == 0) {
                candB = val;
                freqB = 1;
            } else {
                freqA--;
                freqB--;
            }
        }

        freqA = 0;
        freqB = 0;

        for (int val : nums) {
            if (val == candA) freqA++;
            else if (val == candB) freqB++;
        }

        vector<int> result;

        if (freqA > nums.size() / 3) result.push_back(candA);
        if (freqB > nums.size() / 3) result.push_back(candB);

        return result;
    }
};