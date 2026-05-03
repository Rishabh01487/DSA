class Solution {
public:
    bool isMatch(string text, string pattern) {
        int n = text.size(), m = pattern.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return solve(0, 0, text, pattern, dp);
    }

    bool solve(int i, int j, string &s, string &p, vector<vector<int>> &memo) {
        if (j == p.size()) return i == s.size();

        if (memo[i][j] != -1) return memo[i][j];

        bool currentMatch = (i < s.size() && (s[i] == p[j] || p[j] == '.'));

        bool ans;
        if (j + 1 < p.size() && p[j + 1] == '*') {
            ans = solve(i, j + 2, s, p, memo) || 
                  (currentMatch && solve(i + 1, j, s, p, memo));
        } else {
            ans = currentMatch && solve(i + 1, j + 1, s, p, memo);
        }

        return memo[i][j] = ans;
    }
};