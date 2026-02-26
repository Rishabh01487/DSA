class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
    unordered_map<int,int> count, first;
    int degree=0, minLen=nums.size();
    for(int i=0; i<nums.size(); ++i){
        if(!first.count(nums[i])) first[nums[i]]=i;
        count[nums[i]]++;
        if(count[nums[i]]>degree){
            degree=count[nums[i]];
            minLen = i - first[nums[i]] +1;
        } else if(count[nums[i]]==degree){
            minLen = min(minLen, i - first[nums[i]] +1);
        }
    }
    return minLen;
}
};