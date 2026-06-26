class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        unordered_set<int>s;
        int n=grid.size();
        int duplicate=0;
        int actual_sum=0;
        int total= n*n;

        int expected_sum= total*(total+1)/2;
        for(int i=0; i<n;i++){
            for(int j=0;j<n;j++){
                int a =grid[i][j];
                actual_sum+=a;
                if(s.find(a)==s.end()){
                   s.insert(a);
                }
                else {
                    duplicate=a;
                }
            }
        }
        int missing_element=expected_sum-actual_sum + duplicate;
        return{duplicate,missing_element};
    }
};