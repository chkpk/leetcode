class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        if (numCourses == 0) return vector<int>();
        vector<unordered_set<int>> deps(numCourses, unordered_set<int>());
        vector<unordered_set<int>> dep_by(numCourses, unordered_set<int>());
        for (auto& p : prerequisites){
            deps[p.first].insert(p.second);
            dep_by[p.second].insert(p.first);
        }
        vector<int> result;
        unordered_set<int> ok;
        for (int i = 0; i < numCourses; i++)
            if (deps[i].empty()) ok.insert(i);
        while(result.size() < numCourses){
            if (ok.empty()) return vector<int>();
            unordered_set<int> tmp;
            for (int i : ok){
                for (int j : dep_by[i]){
                    deps[j].erase(i);
                    if (deps[j].empty()) tmp.insert(j);
                }
                result.push_back(i);
            }
            ok.swap(tmp);
        }
        return result;
    }
};
