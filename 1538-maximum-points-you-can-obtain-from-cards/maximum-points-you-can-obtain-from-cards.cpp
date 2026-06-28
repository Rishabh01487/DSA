class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        
        int total = 0;
        for (int x : cardPoints) total += x;

        if (k == n) return total;

        int windowSize = n - k;

        int currSum = 0;
        for (int i = 0; i < windowSize; i++) {
            currSum += cardPoints[i];
        }

        int minSum = currSum;

        for (int i = windowSize; i < n; i++) {
            currSum += cardPoints[i];
            currSum -= cardPoints[i - windowSize];
            minSum = min(minSum, currSum);
        }

        return total - minSum;
    }
};