// as we have to find all possible paths hence we use backtracking here
// Runtime: O(4 ^ n), where n is the total number of cells without obstacles.
// Memory: O(n) for the DFS stack.
class Solution {
public:
   // this question is as simple as all unique paths question
    // what the main catch here is-> walk over every non-obstacle square exactly once.
    // this means that we will only count those paths which will travel t_s steps
    int dfs(vector<vector<int>>& g, int i, int j, int s, int t_s) {
     if (i < 0 || j < 0 || i >= g.size() || j >= g[0].size() || g[i][j] == -1) 
        return 0;
     if (g[i][j] == 2) 
        return s == t_s ? 1 : 0;
     g[i][j] = -1;
     int paths = dfs(g, i + 1, j, s + 1, t_s) + dfs(g, i - 1, j, s + 1, t_s) +
       dfs(g, i, j + 1, s + 1, t_s) + dfs(g, i, j - 1, s + 1, t_s);
     g[i][j] = 0;
     return paths;
}
    int uniquePathsIII(vector<vector<int>>& g) {
      auto i1 = 0, j1 = 0, t_steps = 0;
      for (auto i = 0; i < g.size(); ++i)
        for (auto j = 0; j < g[0].size(); ++j) {
          if (g[i][j] == 1) i1 = i, j1 = j;
          if (g[i][j] != -1) ++t_steps;
        }
      return dfs(g, i1, j1, 1, t_steps);
    }
};
