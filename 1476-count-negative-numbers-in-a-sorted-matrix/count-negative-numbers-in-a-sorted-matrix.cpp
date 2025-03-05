class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int ans = 0;
        int  m = grid.size(), n = grid[0].size();
        for(int i =0; i<m; i++) {
            int st = 0, end = n -1;
            while(st <= end ) {
                int mid = st + (end - st) / 2;

                if(grid[i][mid] >=  0) {
                    st = mid+ 1;
                }
                else if(grid[i][mid] < 0) {
                    end = mid -1;
                }

              
            }
             ans += n - st;
        }
        return ans;
    }
};