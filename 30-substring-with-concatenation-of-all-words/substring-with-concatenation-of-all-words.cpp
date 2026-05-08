class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        
        int n = s.size();
        int m = words.size();
        int len = words[0].size();
        int total = m * len;
        
        unordered_map<string, int> mp;
        for (auto &w : words) mp[w]++;
        
        for (int i = 0; i < len; i++) {
            int left = i, count = 0;
            unordered_map<string, int> temp;
            
            for (int j = i; j + len <= n; j += len) {
                string word = s.substr(j, len);
                
                if (mp.count(word)) {
                    temp[word]++;
                    count++;
                    
                    while (temp[word] > mp[word]) {
                        string leftWord = s.substr(left, len);
                        temp[leftWord]--;
                        left += len;
                        count--;
                    }
                    
                    if (count == m) {
                        ans.push_back(left);
                        
                        string leftWord = s.substr(left, len);
                        temp[leftWord]--;
                        left += len;
                        count--;
                    }
                } else {
                    temp.clear();
                    count = 0;
                    left = j + len;
                }
            }
        }
        
        return ans;
    }
};