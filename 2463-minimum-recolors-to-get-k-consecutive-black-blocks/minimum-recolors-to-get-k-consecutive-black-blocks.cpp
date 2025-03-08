class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.size();
        int minOps = INT_MAX; 
        
        
        for (int i = 0; i <= n - k; ++i) {
            int ops = 0; 
            
            
            for (int j = i; j < i + k; ++j) {
                if (blocks[j] == 'W') {
                    ops++;
                }
            }
            
            
            minOps = min(minOps, ops);
        }
        
        return minOps;
        }
};