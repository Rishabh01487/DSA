class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>prefix;
        prefix[0]=1;
        int curr_sum=0;
       int  count=0;
        for(int nums:nums)
        {
            curr_sum+=nums;
            if(prefix.find(curr_sum-k)!=prefix.end())
            {
                count+=prefix[curr_sum-k];
            }
            prefix [curr_sum]++;
        }
     return count;
    }
};