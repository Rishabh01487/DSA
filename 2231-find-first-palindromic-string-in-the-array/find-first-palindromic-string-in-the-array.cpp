class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for (const string& w : words) {
            int l = 0, r = w.size() - 1;
            bool palin = true;
            while (l < r) {
                if (w[l] != w[r]) { palin = false; break; }
                l++; r--;
            }
            if (palin) return w;
        }
        return "";
    }
};