class Solution {
  public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
      if (k == 1) return nums;
      vector<int> result;
      if (nums.size() == 0) return result;
      multiset<int> window;
      for (int i = 0; i < k; i++)
        window.insert(nums[i]);
      result.push_back(*window.rbegin());
      for (int i = k; i < nums.size(); i++){
        auto ite = window.find(nums[i-k]);
        window.erase(ite);
        window.insert(nums[i]);
        result.push_back(*window.rbegin());
      }
      return result;
    }
};
