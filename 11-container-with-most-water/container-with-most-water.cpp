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
            int Area_Curr_container=width*ht;
            maxWater=max(maxWater,Area_Curr_container); 
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