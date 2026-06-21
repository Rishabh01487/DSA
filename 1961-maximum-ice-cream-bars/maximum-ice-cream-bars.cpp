class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());

        int max_bars = 0;

        for(int i = 0; i < costs.size(); i++) {
            if(costs[i] <= coins) {
                coins -= costs[i];
                max_bars++;
            } else {
                break;
            }
        }

        return max_bars;
    }
};