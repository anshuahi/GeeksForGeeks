/*
GeeksForGeeks-POTD: Number of Good Components

POTD Link: https://www.geeksforgeeks.org/problems/number-of-good-components--170647/1

Approach
    1. find a connected component
    2. if the number of edges in the component is equal to n*(n-1) i.e. all nodes are connected to each other nodes. It's good component.
*/
class Solution
{
public:
    void dfs(vector<vector<int>> &gr, int node, vector<bool> &vis, int &nodes, int &noOfEdges)
    {
        if (vis[node])
            return;
        nodes++;
        noOfEdges += gr[node].size();
        vis[node] = true;
        for (auto x : gr[node])
        {
            dfs(gr, x, vis, nodes, noOfEdges);
        }
    }
    int findNumberOfGoodComponent(int e, int v, vector<vector<int>> &edges)
    {
        vector<vector<int>> gr(v + 1);
        for (auto e : edges)
        {
            gr[e[0]].push_back(e[1]);
            gr[e[1]].push_back(e[0]);
        }

        vector<bool> vis(v + 1);
        int ans = 0;
        for (int i = 1; i <= v; i++)
        {
            if (!vis[i])
            {
                int nodes = 0, noOfEdges = 0;
                dfs(gr, i, vis, nodes, noOfEdges);
                if (nodes * (nodes - 1) == noOfEdges)
                    ans++;
            }
        }
        return ans;
    }
};
