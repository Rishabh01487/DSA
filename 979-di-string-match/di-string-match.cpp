class Solution {
public:
    vector<int> diStringMatch(string s) {
        int low = 0, high = s.size();
        vector<int> res;
        for (char c : s) {
            if (c == 'I') res.push_back(low++);
            else res.push_back(high--);
        }
        res.push_back(low); // or high, both are equal now
        return res;
    }
};