class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxWater=0;
        int n=height.size();
        int left=0; 
        int right=n-1;
        while(left<right){
            int width=right-left;
            int ht=min(height[left],height[right]);
            int curr_water_contained=ht*width;
            maxWater=max(maxWater,curr_water_contained);
            if(height[left]<height[right]){
                left++;
            }
            else{
                right--;
            }
        }
        return maxWater;
    }
};