class Solution {
public:
    int n;

    void bfs(vector<int>& edges, int node, vector<int>& dist)
    {
        queue<int> q;
        q.push(node);
        dist[node] = 0;

        vector<bool> vis(n, false);
        vis[node] = true;

        while(!q.empty())
        {
            int u = q.front();
            q.pop();

            int v = edges[u];

            if(v != -1 && !vis[v])
            {
                vis[v] = true;
                dist[v] = 1 + dist[u];
                q.push(v);
            }
        }
    }

    int closestMeetingNode(vector<int>& edges, int node1, int node2)
    {
        n = edges.size();

        vector<int> dist1(n, INT_MAX);
        vector<int> dist2(n, INT_MAX);

        bfs(edges, node1, dist1);
        bfs(edges, node2, dist2);

        int mixdnode = -1;
        int mixdistill = INT_MAX;

        for(int i = 0; i < n; i++)
        {
            if(dist1[i] != INT_MAX && dist2[i] != INT_MAX)
            {
                int maxd = max(dist1[i], dist2[i]);

                if(maxd < mixdistill)
                {
                    mixdistill = maxd;
                    mixdnode = i;
                }
            }
        }

        return mixdnode;
    }
};