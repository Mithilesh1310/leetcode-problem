class Solution {
public:
    int result = -1;
    void dfs(int u,vector<int>& edges,vector<bool>&visited,vector<int>&count,vector<bool>&inrecursion)
    {
        if(u != -1)
        {
            visited[u] = true;
            inrecursion[u] = true;

            int v = edges[u];

            if(v != -1 && !visited[v])
            {
                count[v] = count[u] + 1;
                dfs(v,edges,visited,count,inrecursion);
            }
            else if(v != -1 && inrecursion[v] == true)
            {
                result = max(result,count[u] - count[v] +1);
            }

            inrecursion[u] = false;
        }
    }
    int longestCycle(vector<int>& edges) {
        int n = edges.size();

        vector<int>count(n,1);
        vector<bool>visited(n,false);
        vector<bool>inrecursion(n,false);

        for(int i =0;i<n;i++)
        {
            if(!visited[i])
            {
                dfs(i,edges,visited,count,inrecursion);
            }
        }

        return result;
    }
};