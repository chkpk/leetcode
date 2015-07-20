class Solution {
  public:
    int maximalSquare(vector<vector<char>>& matrix) {
      int n = matrix.size();
      if (n == 0) return 0;
      int m = matrix[0].size();
      if (m == 0) return 0;
      int result = 0;
      vector<vector<int>> ans(n, vector<int>(m, 0));
      for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
          if (matrix[i][j] == '1'){
            ans[i][j] = 1;
            if (i != 0 && j != 0) 
              ans[i][j] += min(min(ans[i - 1][j], ans[i][j - 1]), ans[i - 1][j - 1]);
          }
          result = max(result, ans[i][j]);
        }
      }
      return result * result;
    }
};
