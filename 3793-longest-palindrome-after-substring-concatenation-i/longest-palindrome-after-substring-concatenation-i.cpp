class Solution {
public:
    void expand(string &s, vector<int>& p, int l, int r) {
        while(l >= 0 && r < s.size() && s[l] == s[r]) {
            p[l] = max(p[l], r - l + 1);
            l--;
            r++;
        }
    }

    vector<int> getPal(string &s) {
        int n = s.size();
        vector<int> p(n, 1);

        for(int i = 0; i < n; i++) {
            expand(s, p, i, i);
            expand(s, p, i, i + 1);
        }

        return p;
    }

    int longestPalindrome(string s, string t) {
        int n = s.size(), m = t.size();

        string rt = t;
        reverse(rt.begin(), rt.end());

        vector<int> a = getPal(s);
        vector<int> b = getPal(rt);

        int ans = 1;

        for(int x : a) ans = max(ans, x);
        for(int x : b) ans = max(ans, x);

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(s[i - 1] == rt[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;

                    ans = max(ans, dp[i][j] * 2);

                    if(i < n)
                        ans = max(ans, dp[i][j] * 2 + a[i]);

                    if(j < m)
                        ans = max(ans, dp[i][j] * 2 + b[j]);
                }
            }
        }

        return ans;
    }
};