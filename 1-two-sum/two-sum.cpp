class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mp;
        int n=nums.size();
         for(int i=0;i<n;i++){
        int num=nums[i];
        int moreNeeded=target-num;
            if(mp.find(moreNeeded)==mp.end()){
                mp.insert({num,i});
            }
            else 
            return {mp[moreNeeded],i};        
            }
     return {};
    }
};