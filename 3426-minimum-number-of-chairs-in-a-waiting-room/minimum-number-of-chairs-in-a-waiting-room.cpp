class Solution {
public:
    int minimumChairs(string s) {
        int curr = 0, ans = 0;

        for (char ch : s) {
            if (ch == 'E') {
                curr++;
                ans = max(ans, curr);
            } else {
                curr--;
            }
        }

        return ans;
    }
};