class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    unordered_set<int> s(nums1.begin(), nums1.end());
    vector<int> res;
    for(int x: nums2){
        if(s.count(x)){
            res.push_back(x);
            s.erase(x);
        }
    }
    return res;
}
};