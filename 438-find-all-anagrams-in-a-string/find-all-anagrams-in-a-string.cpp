class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int sLength = s.size();
        int pLength = p.size();
        vector<int> result;
    
        if (sLength < pLength) {
            return result;
        }
      
        vector<int> patternCount(26, 0);
        for (char& ch : p) {
            patternCount[ch - 'a']++;
        }
      
        vector<int> windowCount(26, 0);
        for (int i = 0; i < pLength - 1; i++) {
            windowCount[s[i] - 'a']++;
        }

        for (int i = pLength - 1; i < sLength; i++) {
        
            windowCount[s[i] - 'a']++;
          
             
            if (windowCount == patternCount) {
                result.push_back(i - pLength + 1);  
            }
          
            
            windowCount[s[i - pLength + 1] - 'a']--;
        }
      
        return result;
        
    }
};