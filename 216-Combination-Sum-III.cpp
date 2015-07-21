class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        set<int> used;
        vector<vector<int>> ans;
        dp(k, n, used, ans);
        return ans;
    }

    void dp(int k, int n, set<int>& used, vector<vector<int>>& ans){
        if (k == 0 && n == 0){
            ans.push_back(vector<int>(used.begin(), used.end()));
            return;
        }
        if (k == 0 || n == 0)   return;
        int start = (used.empty())? 1 : *used.rbegin() + 1;
        int end = min(10, n + 1);
        for (int i = start; i < end; i++){
            used.insert(i);
            dp(k - 1, n - i, used, ans);
            used.erase(i);
        }
        return;
    }
};
