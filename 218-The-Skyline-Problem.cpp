class Solution {
  public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
      vector<pair<int, int>> result;
      if (buildings.size() == 0) return result;
      multimap<int, int> key_points;  // 记录所有可能出现key points的x坐标，key为x值，value为在buildings的下表
      for (int i = 0; i < buildings.size(); i++){
        key_points.insert(make_pair(buildings[i][0], i));
        key_points.insert(make_pair(buildings[i][1], i));
      }
      multimap<int, int> current_blocks;  // 覆盖当前key point的building， key为高度，value为在buildings的下标 
      int current_height = 0;             // 当前高度
      while (key_points.size() > 0){
        // 获取左边界或右边界在当前key point的building
        auto points = key_points.equal_range(key_points.begin()->first);
        vector<int> leave_blocks;   // 所有右边界在key point上的building 的下标 
        for (auto ite = points.first; ite != points.second; ++ite){
          int index = ite->second;
          if (ite->first == buildings[index][0])
            // 添加所有左边界在当前key point的building
            current_blocks.insert(make_pair(buildings[index][2], index)); 
          else
            leave_blocks.push_back(index);
        }
        // 移除所有右边界在当前key point的building
        for (int index : leave_blocks){
          int h = buildings[index][2];
          auto ite_pair = current_blocks.equal_range(h);
          for (auto ite = ite_pair.first; ite != ite_pair.second; ++ite){
            if (ite->second == index){
              current_blocks.erase(ite);
              break;
            }
          }
        }
        // 获取覆盖当前key point的所有building的最高高度
        int height = 0;
        if (current_blocks.size() > 0)
          height = current_blocks.rbegin()->first;
        if (height != current_height){ 
          // real key point found
          result.push_back(make_pair(key_points.begin()->first, height));
          current_height = height;    
        }
        // 移除已检查的key point
        for (auto ite = points.first; ite != points.second; ++ite)
          key_points.erase(ite);
      }
      return result;
    }
};
