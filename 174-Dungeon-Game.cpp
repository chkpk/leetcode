class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = dungeon.size();
        if (n == 0) return 1;
        int m = dungeon[0].size();
        if (m == 0) return 1;
        vector<vector<long>> result(n, vector<long>(m, LONG_MAX));
        result[n-1][m-1] = max(1L - dungeon[n-1][m-1], 1L);
        for (int i = n - 1; i >= 0; i--)
            for (int j = m - 1; j >= 0; j--){
                if (i < n - 1)
                    result[i][j] = min(result[i][j], max(result[i+1][j] - dungeon[i][j], 1L));
                if (j < m - 1)
                    result[i][j] = min(result[i][j], max(result[i][j+1] - dungeon[i][j], 1L));
            }
        return result[0][0];
    }
};
