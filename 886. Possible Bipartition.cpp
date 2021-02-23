class Solution
{
    bool isBipartite(int node, vector<vector<int>> &adj, vector<int> &color)
    {
        queue<int> q;
        q.push(node);
        color[node] = 1;

        while (!q.empty())
        {
            int curr = q.front();
            q.pop();

            for (int ele : adj[curr])
            {
                // Two adjacent vertex have same color
                if (color[ele] == color[curr])
                    return false;

                // If it is colorless, then color it with different color as parent node
                else if (color[ele] == -1)
                {
                    color[ele] = 1 - color[curr];
                    q.push(ele);
                }
            }
        }
        return true;
    }

public:
    bool possibleBipartition(int N, vector<vector<int>> &dislikes)
    {
        // Adjacency list
        vector<vector<int>> adj(N + 1);

        // Build a Undirected graph. Undirected Graph Why ?
        // Because if (a,b) a dislikes b is equivalent to b dislikes a.
        for (int i = 0; i < dislikes.size(); i++)
        {
            adj[dislikes[i][0]].push_back(dislikes[i][1]);
            adj[dislikes[i][1]].push_back(dislikes[i][0]);
        }

        // Color(1 & 0 are two color) & Initialize with -1(Colorless)
        vector<int> color(N + 1, -1);

        for (int i = 1; i <= N; i++)
        {
            // If it is colorless, then color it and check if 
            //two adjacent vertex have same color then return false
            if (color[i] == -1 && !isBipartite(i, adj, color))
                return false;
        }
        return true;
    }
};
